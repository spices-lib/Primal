using System.Windows;
using System.Windows.Controls;

namespace PrimalEditor.Source.GameProject;

public partial class NewProjectView : UserControl
{
    public NewProjectView()
    {
        InitializeComponent();
    }

    private void OnCreat_Button_Click(object sender, RoutedEventArgs e)
    {
        var vm = DataContext as NewProject;
        var projectPath = vm.CreateProject(TemplateListBox.SelectedItem as ProjectTemplate);
        bool dialogResult = false;
        var win = Window.GetWindow(this);
        if (!string.IsNullOrEmpty(projectPath))
        {
            dialogResult = true;
            var project = OpenProject.Open(new ProjectData() { ProjectName = vm.ProjectName, ProjectPath = projectPath });
        }

        win.DialogResult = dialogResult;
        win.Close();
    }
}