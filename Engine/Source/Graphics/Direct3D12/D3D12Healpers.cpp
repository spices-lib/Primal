#include "D3D12Healpers.h"
#include "D3D12Core.h"

namespace primal::graphics::d3d12::d3dx {

	namespace {
	
	}

	ID3D12RootSignature* create_root_signature(const d3d12_root_signature_desc& desc)
	{
		D3D12_VERSIONED_ROOT_SIGNATURE_DESC versioned_desc{};
		versioned_desc.Version = D3D_ROOT_SIGNATURE_VERSION_1_1;
		versioned_desc.Desc_1_1 = desc;

		using namespace Microsoft::WRL;
		
		ComPtr<ID3DBlob> signture_blob{ nullptr };
		ComPtr<ID3DBlob> error_blob{ nullptr };
		HRESULT hr{ S_OK };
		if (FAILED(hr = D3D12SerializeVersionedRootSignature(&versioned_desc, &signture_blob, &error_blob)))
		{
			DEBUG_OP(const char* error_msg{ error_blob ? (const char*)error_blob->GetBufferPointer() : "" });
			DEBUG_OP(OutputDebugStringA(error_msg));
			return nullptr;
		}

		ID3D12RootSignature* signature{ nullptr };
		DXCall(core::device()->CreateRootSignature(0, signture_blob->GetBufferPointer(), signture_blob->GetBufferSize(), IID_PPV_ARGS(&signature)));

		if (FAILED(hr))
		{
			core::release(signature);
		}

		return signature;
	}

	ID3D12PipelineState* create_pipeline_state(D3D12_PIPELINE_STATE_STREAM_DESC desc)
	{
		assert(desc.pPipelineStateSubobjectStream && desc.SizeInBytes);
		ID3D12PipelineState* pso{ nullptr };
		DXCall(core::device()->CreatePipelineState(&desc, IID_PPV_ARGS(&pso)));
		assert(pso);
		return pso;
	}

	ID3D12PipelineState* create_pipeline_state(void* stream, u64 stream_size)
	{
		assert(stream && stream_size);
		D3D12_PIPELINE_STATE_STREAM_DESC desc{};
		desc.SizeInBytes = stream_size;
		desc.pPipelineStateSubobjectStream = stream;
		return create_pipeline_state(desc);
	}
}