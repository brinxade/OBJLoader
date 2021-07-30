#pragma once
#include<string>
#include<iostream>
#include<fstream>
#include<sstream> 
#include<cstdint>
#include<vector>

using namespace std;

class OBJLoader
{
private:
	string filename;
	vector<float> vertices, normals, uv;
	uint32_t vertexCount, normalCount, uvCount;

public:
	OBJLoader(string filename)
	{
		this->filename = filename;
		this->vertexCount = 0;
		this->normalCount = 0;
		this->uvCount = 0;

		load();
	}

	void load()
	{
		ifstream file(filename);
		if (file.is_open())
		{
			string line, token, face;
			float v1 = 0, v2 = 0, v3 = 0, n1 = 0, n2 = 0, n3 = 0, t1 = 0, t2 = 0;

			while (getline(file, line))
			{
				istringstream iss(line);
				getline(iss, token, ' ');
				
				if (token == "#")
					continue;

				if (token == "v")
				{
					iss >> v1 >> v2 >> v3;
					vertices.insert(vertices.end(), { v1, v2, v3 });
					++vertexCount;
				}
				else if (token == "vn")
				{
					iss >> n1 >> n2 >> n3;
					normals.insert(normals.end(), { n1, n2, n3 });
					++normalCount;
				}
				else if (token == "vt")
				{
					iss >> t1 >> t2;
					uv.insert(uv.end(), { t1, t2 });
					++uvCount;
				}
				else if (token == "f")
				{
					while (!iss.eof())
					{
						iss >> face;
						//create vertex data here

					}

					std::cout << face << std::endl;
				}
			}
		}
	}

	uint32_t getVertexCount()
	{
		return vertexCount;
	}

	uint32_t getNormalCount()
	{
		return normalCount;
	}

	uint32_t getUVCount()
	{
		return uvCount;
	}
};