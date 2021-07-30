#include"OBJLoader.h"

int main()
{
	OBJLoader obj("sample input/cube.obj");

	std::cout << "Draw Vertex Count: " << obj.getDrawVertexCount() << std::endl;
	std::cout << "Vertex Count: " << obj.getVertexCount() << std::endl;
	std::cout << "Normal Count: " << obj.getNormalCount() << std::endl;
	std::cout << "UV Count: " << obj.getUVCount() << std::endl;
	std::cout << "Face Count: " << obj.getUVCount() << std::endl << std::endl;

	obj.show();
}