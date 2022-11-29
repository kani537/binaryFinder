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

  std::cout << "size = " << size << "\n";
  for (int i = 0; i < size - 6; i++)
  {
    if ((data[i] & 0xFF) == 0x84 && (data[i + 1] & 0xFF) == 0xFF && (data[i + 2] & 0xFF) == 0xFF && (data[i + 3] & 0xFF) == 0xEB && (data[i + 5] & 0xFF) == 0x30 && (data[i + 6] & 0xFF) == 0xA0)
      cout << "0x" << std::hex << i + 1 << endl;
  }
  delete[] data;
  return 0;
}