#pragma once

#include <vector>
#include <string>
#include <memory>
#include <map>

/*
	The Flyweight pattern is a design pattern that allows for 
	the efficient sharing of a large number of similar 
	objects by storing their intrinsic, or shared state 
	externally and passing it to the objects as needed,
	thus reducing memory usage and improving performance.

	In this example, a Model class receives a pointer to
	a mesh by calling the MeshFactory class, which creates
	a new Mesh object from a file if not already created
	and stores it in a map. If another Model is created
	with the same Mesh, the MeshFactory simply returns the 
	pointer to the already created Mesh, thus improving 
	memory and performance.
*/

struct vec3 {
	float x, y, z;
};

struct Mesh {
	Mesh(const std::string& meshFile) {
		//load mesh file into positions and indices
	}

	std::vector<vec3> positions;
	std::vector<unsigned int> indices;
};

class MeshFactory {
public:
	std::shared_ptr<Mesh> getMesh(const std::string& meshFile) {
        if (meshes.count(meshFile) == 0) {
			meshes[meshFile] = std::make_shared<Mesh>(meshFile);
        }
        return meshes[meshFile];
    }

private:
    std::map<std::string, std::shared_ptr<Mesh>> meshes;
};

class Model {
public:

	Model(const std::string& modelName, const std::string& meshFile)
		: m_name(modelName)
	{
		m_mesh = m_meshFactory.getMesh(meshFile);
	}

private:
	std::string m_name;
	std::shared_ptr<Mesh> m_mesh;
	static MeshFactory m_meshFactory;
};