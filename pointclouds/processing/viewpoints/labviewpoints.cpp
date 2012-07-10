#include <iomanip>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/io/pcd_io.h>
#include <pcl/common/transforms.h>
#include <vtkPLYReader.h>
#include <vtkOBJReader.h>
#include <vtkPolyDataMapper.h>
#include <pcl/filters/voxel_grid.h>
#include <pcl/console/print.h>
#include <pcl/console/parse.h>

using namespace std;

int
main (int argc, char** argv)
{
	//Interesting viewpoints for our case.
	int n_valid = 13;
	float valid_points[] = {3,4,5,6,14,27,28,29,34,35,37,39,41};
	
	int resolution = 100;
	int tesselated_sphere_level = 1;
	
	vtkSmartPointer<vtkPolyData> polydata1;
	vtkSmartPointer<vtkPLYReader> readerQuery = vtkSmartPointer<vtkPLYReader>::New ();
    readerQuery->SetFileName (argv[1]);
    polydata1 = readerQuery->GetOutput ();
    polydata1->Update ();
    
	pcl::visualization::PCLVisualizer vis;
	vis.addModelFromPolyData (polydata1, "mesh1", 0);
	vis.setRepresentationToSurfaceForAllActors ();

	std::vector<pcl::PointCloud<pcl::PointXYZ> , Eigen::aligned_allocator<pcl::PointCloud<pcl::PointXYZ> > > views_xyz;
	std::vector<Eigen::Matrix4f, Eigen::aligned_allocator<Eigen::Matrix4f> > poses;
	std::vector<float> enthropies;
	vis.renderViewTesselatedSphere (resolution, resolution, views_xyz, poses, enthropies, tesselated_sphere_level, 45, 1, true);
	
	
	for (size_t i = 0; i < n_valid; i++)
	{
		pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ> ());
		string name (argv[1]);
		name.erase(name.end()-4, name.end());
		name.erase(name.begin(), name.end()-7);
		
		char name2[15];
		stringstream ss;
		ss << name << "_" << setfill ('0') << setw(3) << i << ".pcd";		
		pcl::io::savePCDFileASCII (ss.str(), views_xyz[valid_points[i]]);
	}
}
