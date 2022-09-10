/******************************************************************************

                              Online C++ Debugger.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Debug" button to debug it.

*******************************************************************************/

#include <iostream>
#include <algorithm>
#include <random>
#include <ctime>
#include <list>
#include <execution>
#include <chrono>
#include <cstdlib>  // where atoi() is located
#include <unistd.h> // where getopt() is located
#include <cstring>
#include "sets.h"
#define SIZE 100000
using namespace std;


//main function


int main (int argc, char *argv[])
{
  int iterations, data_key, read_only_ratio, opt;
  char ds[10];
  const char *options = "i:k:d:r:"; // possible options, : for option with associated value
  if (argc != 5)
    {
      cout << "Print Usage ..." << endl;
      return 0;
    }
    // iterate through the command-line arguments
    while((opt = getopt(argc, argv, options)) != -1){
        switch(opt){ // return value of getopt
            case 'i':
               iterations = atoi(optarg); //optarg contains the value associated with the option i
               break;
            case 'k':
                data_key = atoi(optarg);
                break;
            case 'd':
                strcpy(ds, optarg);
                break;
            case 'r':
                read_only_ratio = atoi(optarg);
                break;
            default:
                cout << "Invalid option." << endl;;
                cout << "Print Usage ..." << endl;
                return 0;
        }
    }
    if(strcmp(ds, "list")== 0){
      ListSet dataset;
      for (int i = 0; i < data_key / 2; i++)
            dataset.insert (rand () % data_key);

      int read_only = read_only_ratio * iterations / 100;
      int read_write = (iterations - read_only) / 2;
      // list < int >list (list.begin (), list.end ());
      for (int i = 0; i < read_only; i++)
        {
         auto start = chrono::high_resolution_clock::now ();
        dataset.find(rand () % data_key);
        auto end = chrono::high_resolution_clock::now ();
        cout << "find execution time = " <<
            chrono::duration_cast < std::chrono::nanoseconds >
            (end - start).count () << endl;
        }
      for (int i = 0; i < read_write; i++)
        {
        auto start = chrono::high_resolution_clock::now ();
        dataset.insert (rand () % data_key);
        auto end = chrono::high_resolution_clock::now ();
        cout << "insert execution time = " <<
        chrono::duration_cast < std::chrono::nanoseconds >
        (end - start).count () << endl;
         }
      for (int i = 0; i < read_write; i++){
          auto start = chrono::high_resolution_clock::now ();
            dataset.remove (rand () % data_key);
            auto end = chrono::high_resolution_clock::now ();
        cout << "remove execution time = " <<
        chrono::duration_cast < std::chrono::nanoseconds >
        (end - start).count () << endl;
      }
    }
    else if(strcmp(ds, "array")== 0){
      arraySet dataset;
      for (int i = 0; i < data_key / 2; i++)
            dataset.insert (rand () % data_key);

    
      int read_only = read_only_ratio * iterations / 100;
      int read_write = (iterations - read_only) / 2;

      // list < int >list (list.begin (), list.end ());
      for (int i = 0; i < read_only; i++)
        {
         auto start = chrono::high_resolution_clock::now ();
        dataset.find(rand () % data_key);
        auto end = chrono::high_resolution_clock::now ();
        cout << "find execution time = " <<
            chrono::duration_cast < std::chrono::nanoseconds >
            (end - start).count () << endl;
        }

      for (int i = 0; i < read_write; i++)
        {
        auto start = chrono::high_resolution_clock::now ();
        dataset.insert (rand () % data_key);
        auto end = chrono::high_resolution_clock::now ();
        cout << "insert execution time = " <<
        chrono::duration_cast < std::chrono::nanoseconds >
        (end - start).count () << endl;
    }
      for (int i = 0; i < read_write; i++){
          auto start = chrono::high_resolution_clock::now ();
            dataset.remove (rand () % data_key);
            auto end = chrono::high_resolution_clock::now ();
        cout << "remove execution time = " <<
        chrono::duration_cast < std::chrono::nanoseconds >
        (end - start).count () << endl;
      }
    }
    else if(strcmp(ds, "tree") == 0){
      treeSet dataset;
      for (int i = 0; i < data_key / 2; i++)
            dataset.insert (rand () % data_key);

    
      int read_only = read_only_ratio * iterations / 100;
      int read_write = (iterations - read_only) / 2;

      // list < int >list (list.begin (), list.end ());
      for (int i = 0; i < read_only; i++)
        {
         auto start = chrono::high_resolution_clock::now ();
        dataset.find(rand () % data_key);
        auto end = chrono::high_resolution_clock::now ();
        cout << "find execution time = " <<
            chrono::duration_cast < std::chrono::nanoseconds >
            (end - start).count () << endl;
        }

      for (int i = 0; i < read_write; i++)
        {
        auto start = chrono::high_resolution_clock::now ();
        dataset.insert (rand () % data_key);
        auto end = chrono::high_resolution_clock::now ();
        cout << "insert execution time = " <<
        chrono::duration_cast < std::chrono::nanoseconds >
        (end - start).count () << endl;
    }
      for (int i = 0; i < read_write; i++){
          auto start = chrono::high_resolution_clock::now ();
            dataset.remove (rand () % data_key);
            auto end = chrono::high_resolution_clock::now ();
        cout << "remove execution time = " <<
        chrono::duration_cast < std::chrono::nanoseconds >
        (end - start).count () << endl;
      }
    }
    else if(strcmp(ds, "hash")== 0){
      hashSet dataset;
      for (int i = 0; i < data_key / 2; i++)
            dataset.insert (rand () % data_key);

    
      int read_only = read_only_ratio * iterations / 100;
      int read_write = (iterations - read_only) / 2;

      // list < int >list (list.begin (), list.end ());
      for (int i = 0; i < read_only; i++)
        {
         auto start = chrono::high_resolution_clock::now ();
        dataset.find(rand () % data_key);
        auto end = chrono::high_resolution_clock::now ();
        cout << "find execution time = " <<
            chrono::duration_cast < std::chrono::nanoseconds >
            (end - start).count () << endl;
        }

      for (int i = 0; i < read_write; i++)
        {
        auto start = chrono::high_resolution_clock::now ();
        dataset.insert (rand () % data_key);
        auto end = chrono::high_resolution_clock::now ();
        cout << "insert execution time = " <<
        chrono::duration_cast < std::chrono::nanoseconds >
        (end - start).count () << endl;
    }
      for (int i = 0; i < read_write; i++){
          auto start = chrono::high_resolution_clock::now ();
            dataset.remove (rand () % data_key);
            auto end = chrono::high_resolution_clock::now ();
        cout << "remove execution time = " <<
        chrono::duration_cast < std::chrono::nanoseconds >
        (end - start).count () << endl;
      }
    }
    else{
        cout << "Invalid data structure" << endl;
    }


      return 0;
}