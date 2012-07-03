#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/io/openni_grabber.h>
#include <pcl/visualization/cloud_viewer.h>
#include <string>
#include <sstream>

#ifdef _WIN32
# define sleep(x) Sleep((x)*1000)
#endif

 class SimpleOpenNIViewer
 {
   public:
     SimpleOpenNIViewer () : viewer ("PCL OpenNI Viewer") {}

     void cloud_cb_ (const pcl::PointCloud<pcl::PointXYZRGBA>::ConstPtr &cloud)
     {
		 
		static unsigned count = 0;
		static unsigned int pcd_count = 1;
		static double last = pcl::getTime ();
		if (++count == 30)
		{
		  double now = pcl::getTime ();
		  std::cout << "distance of center pixel :" << cloud->points [(cloud->width >> 1) * (cloud->height + 1)].z << " mm. Average framerate: " << double(count)/double(now - last) << " Hz" <<  std::endl;
		  count = 0;
		  last = now;

		  
		  std::string name("nube_");
		  std::ostringstream number;
		  number << pcd_count;
		  name.append(number.str());
		  name.append(".pcd");
		  pcl::io::savePCDFileASCII (name, *cloud);
		  std::cout<<"Saved PCD: "<< name << endl;
		  pcd_count++;
		}
       if (!viewer.wasStopped())
         viewer.showCloud (cloud);
     }

     void run ()
     {
       pcl::Grabber* interface = new pcl::OpenNIGrabber();

       boost::function<void (const pcl::PointCloud<pcl::PointXYZRGBA>::ConstPtr&)> f =
         boost::bind (&SimpleOpenNIViewer::cloud_cb_, this, _1);

       interface->registerCallback (f);

       interface->start ();

       while (!viewer.wasStopped())
       {
         boost::this_thread::sleep (boost::posix_time::seconds (1));
       }

       interface->stop ();
     }

     pcl::visualization::CloudViewer viewer;
 };

 int main ()
 {
   SimpleOpenNIViewer v;
   v.run ();
   return 0;
 }
