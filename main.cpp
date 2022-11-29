#include <iostream>
#include <string>
#include <stdio.h>
#include <fstream>
using namespace std;

int main(void)
{
  string fileName;

  getline(cin, fileName);

  std::ifstream ifs(fileName, std::ios::binary);

  ifs.seekg(0, std::ios::end);
  long long int size = ifs.tellg();
  ifs.seekg(0);

  char *data = new char[size];
  ifs.read(data, size);

  std::cout << "size = " << size << endl;

  getline(cin, fileName);

  std::ifstream ifs1(fileName, std::ios::binary);

  ifs1.seekg(0, std::ios::end);
  size = ifs1.tellg();
  ifs1.seekg(0);

  char *data1 = new char[size];
  ifs1.read(data1, size);

  std::cout << "size = " << size << endl;
  for (int i = 0; i < size; i++)
  {
    if (data[i] != data1[i])
      cout << i << endl;
  }
  delete[] data;
  return 0;
}