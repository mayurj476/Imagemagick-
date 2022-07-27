/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <memory>
#include <queue>
#include <thread>
#include <Magick++.h>
#include <bits/stdc++.h>

using namespace std;
using namespace Magick; 
mutex m;
condition_variable cd;
queue<string> my;
void process()
{
    cout << "process:bedore " << endl;
    unique_lock<mutex> lk(m);
    cd.wait(lk,[](){return my.size()>0;});
    cout << "process: " << my.front() << endl;
    my.pop();
}

void addjob(string a)
{
    //  lock_guard<std::mutex> lk(m);
    cout << "add job for: " << a << endl;
    my.push(a);
    cd.notify_all();
}

int main(int argc,char **argv)
{

InitializeMagick(*argv);


 // Construct the image object. Seperating image construction from the 
  // the read operation ensures that a failure to read the image file 
  // doesn't render the image object useless. 
  Image image;
  try { 
    // Read a file into image object 
    image.read( "logo:" );

    // Crop the image to specified size (width, height, xOffset, yOffset)
    image.crop( Geometry(1400,1400, 400, 400) );
    image.rotate(60);
    image.addNoise(NoiseType::ImpulseNoise);
    // Write the image to a file 
    image.write( "logo.png" ); 
  } 
  catch( Exception &error_ ) 
    { 
      cout << "Caught exception: " << error_.what() << endl; 
      return 1; 
    } 


    return 0;
}
