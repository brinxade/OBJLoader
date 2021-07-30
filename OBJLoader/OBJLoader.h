#pragma once
#include<string>
#include<iostream>
#include<fstream>
#include<sstream> 
#include<cstdint>
#include<vector>

class OBJLoader
{
private:
	std::string filename;
	std::vector<float> vertices, normals, uv, vertexData;
	uint32_t vertexCount, normalCount, uvCount, faceCount, drawVertexCount;

	void load()
	{
		std::ifstream file(filename);
		if (file.is_open())
		{
			std::string line, token, face;
			float v1 = 0, v2 = 0, v3 = 0, n1 = 0, n2 = 0, n3 = 0, t1 = 0, t2 = 0;
			uint32_t f_vertex = 0, f_uv = 0, f_normal = 0;

			while (std::getline(file, line))
			{
				std::istringstream iss(line);
				std::getline(iss, token, ' ');
				
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
					// n-vertices in a face
					while (!iss.eof())
					{
						iss >> face;
						std::istringstream face_vertex_iss(face);
						std::string face_vertex_attrib;
						++faceCount;

						// 0=vertex, 1=texture coordinats, 2=normals
						int attrib_type = 0;
						while (std::getline(face_vertex_iss, face_vertex_attrib, '/'))
						{
							bool is_empty = face_vertex_attrib.empty();
							int index = is_empty ? 0 : std::stoi(face_vertex_attrib) - 1;

							if (attrib_type == 0 && !is_empty)
							{
								index *= 3;
								vertexData.insert(vertexData.end(), { vertices[index], vertices[index + 1], vertices[index + 2] });
							}
							else if (attrib_type == 1 && !is_empty)
							{
								index *= 2;
								vertexData.insert(vertexData.end(), { uv[index], uv[index + 1] });
							}
							else if (attrib_type == 2 && !is_empty)
							{
								index *= 3;
								vertexData.insert(vertexData.end(), { normals[index], normals[index + 1], normals[index + 2] });
							}
							++attrib_type;
						}
					}
				}
			}
		}
	}

public:
	OBJLoader(std::string filename)
	{
		this->filename = filename;
		this->vertexCount = 0;
		this->normalCount = 0;
		this->uvCount = 0;
		this->faceCount = 0;
		this->drawVertexCount = 0;

		load();
	}

	void show()
	{
		for (float x : vertexData)
			std::cout << x << " ";
	}

	float* getVertexData()
	{
		return vertexData.data();
	}

	uint32_t getFaceCount()
	{
		return faceCount;
	}

	uint32_t getDrawVertexCount()
	{
		return faceCount * 3;
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