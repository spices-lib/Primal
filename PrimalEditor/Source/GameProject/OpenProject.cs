using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Diagnostics;
using System.IO;
using System.Runtime.Serialization;

namespace PrimalEditor.Source.GameProject;

[DataContract]
public class ProjectData
{
    [DataMember]
    public string ProjectName { get; set; }
    [DataMember]
    public string ProjectPath { get; set; }
    [DataMember]
    public DateTime Data { get; set; }
}

[DataContract]
public class ProjectDataList
{
    [DataMember]
    public List<ProjectData> Projects { get; set; }
}

class OpenProject
{
    private static readonly string _applicationDataPath =
        $@"{Environment.GetFolderPath(Environment.SpecialFolder.ApplicationData)}\PrimalEditor\";

    private static readonly string _projectDataPath;
    private static readonly ObservableCollection<ProjectData> _projects = new();
    public static ReadOnlyObservableCollection<ProjectData> Projects { get; }

    private static void ReadProjectData()
    {

    }

    public static Project Open(ProjectData projectData)
    {
        ReadProjectData();
    }

    static OpenProject()
    {
        try
        {
            if (!Directory.Exists(_applicationDataPath)) Directory.CreateDirectory(_applicationDataPath);
            _projectDataPath = $@"{_applicationDataPath}ProjectData.xml";
            Projects = new(_projects);
            ReadProjectData();
        }
        catch (Exception e)
        {
            Debug.WriteLine(e.Message);
        }
    }
}