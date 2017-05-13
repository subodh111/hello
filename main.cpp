#include<iostream>
#include<fstream>
using namespace std;

struct points
{
	int x;
	int y;
	int z;
};

int main()
{
	const int size = 3;
	points array1[size];
	for (int i = 0; i < size; i++)
	{
		cout << "Enter coordinate points for " << i << ":";
		cin >> array1[i].x >> array1[i].y >> array1[i].z;
	}

	fstream f("goodfile.dat", ios::out | ios::binary);

	if (f)
	{
		f.write(reinterpret_cast<char*>(array1),
			size * sizeof(points));
			f.close();
	}
	else
		cout << "Error!\n";


	f.open("goodfile.dat", ios::in | ios::binary);

	int p;
    cout<<"Enter the points you want to retrieve :";
    cin>> p;
	if (f)
	{
		points array2[size];

		f.read(reinterpret_cast<char*>(array2),
			size * sizeof(points));
		f.close();


cout<<"The coordinates of your points :";
			cout << array2[p].x << " " << array2[p].y<<" "<< array2[p].z << endl;
	}
	else
		cout << "Error!\n";
	cin.get();
}

