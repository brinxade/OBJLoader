#include"OBJLoader.h"

int main()
{
	OBJLoader obj("sample input/human.obj");
	std::cout << "Vertex Count: " << obj.getVertexCount() << std::endl;
	std::cout << "Normal Count: " << obj.getNormalCount() << std::endl;
	std::cout << "UV Count: " << obj.getUVCount() << std::endl;
}