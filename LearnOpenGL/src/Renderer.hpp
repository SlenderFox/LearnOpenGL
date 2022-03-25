#pragma region
#pragma once
#include <glad/glad.h> // Include glad to get all the required OpenGL headers
#include "Camera.hpp"
#include "Mesh.hpp"
#include "Light.hpp"
#pragma endregion

namespace Engine
{
	class Renderer
	{
		friend class Application;	// Allowing application access and control
	public:
		static Renderer* GetInstance()
		{
			static Renderer* sm_instance = new Renderer();
			return sm_instance;
		}

		/**
		 * @brief Create a Vertex Array Object on the GPU using opengl
		 * 
		 * @param pidVAO Storage for the id of the VAO, passed by reference
		 * @param pidVBO Storage for the id of the VBO, passed by reference
		 * @param pidEBO Storage for the id of the EBO, passed by reference
		 * @param pVertices Reference to the array of vertices to be used
		 * @param pVertexSize The size of the array of vertices
		 * @param pIndices Reference to the array of indices to be used
		 * @param pIndexSize The size of the array of indices
		 */
		void CreateVAO(unsigned int* pidVAO, unsigned int* pidVBO, unsigned int* pidEBO,
		 float* pVertices[], const size_t pVertexSize, unsigned int* pIndices[], const size_t pIndexSize);
		/**
		 * @brief Create a Vertex Array Object on the GPU using opengl.
		 * This overload works as a wrapper for the other overload and it is
		 * recommended you use this one instead.
		 * 
		 * @param pidVAO Storage for the id of the VAO, passed by reference
		 * @param pidVBO Storage for the id of the VBO, passed by reference
		 * @param pidEBO Storage for the id of the EBO, passed by reference
		 * @param pVertices Reference to a vector of vertices to be used
		 * @param pIndices Reference to a vector of indices to be used
		 */
		void CreateVAO(unsigned int* pidVAO, unsigned int* pidVBO, unsigned int* pidEBO,
		 vector<float>* pVertices, vector<unsigned int>* pIndices);

		// Temporary
		void CreateLightVAO(unsigned int* pidVAO, unsigned int* pidVBO, float* pVertices[], const size_t pVertexSize);
		void CreateLightVAO(unsigned int* pidVAO, unsigned int* pidVBO, vector<float>* pVertices);

	private:
		#pragma region Constructors
		Renderer() = default;
		~Renderer() {}
		// Delete copy/move so extra instances can't be created/moved.
		Renderer(const Renderer&) = delete;
		Renderer& operator=(const Renderer&) = delete;
		Renderer(Renderer&&) = delete;
		Renderer& operator=(Renderer&&) = delete;
		#pragma endregion

		/**
		 * @brief Initlialises the renderer
		 *
		 * @return If initlialisation was successful
		 */
		void Init(float pAspect);
		/**
		 * @brief Destroys the renderer but only if it was ever initliased
		 *
		 * @param pValidate Whether the renderer was even initialised
		 */
		void Destroy(bool pValidate);
		/**
		 * @brief Draws the scene
		 *
		 * @param pCamera TEMPORARY! The viewprojection matrix used as the camera
		 * @param pTime TEMPORARY! Used for basic shape animation
		 * @remark Only Application is able to call this function
		 */
		void Draw(double pTime);

		#pragma region Getters
		/**
		 * @brief Get a pointer to the mesh object at a given position
		 * 
		 * @param pPos The position in the array of the mesh
		 * @return Mesh* The pointer to the mesh object
		 */
		Mesh* GetMeshAt(unsigned int pPos);
		/**
		 * @brief Get a pointer to the shader object at a given position
		 * 
		 * @param pPos The position in the array of the shader
		 * @return Shader* The pointer to the shader object
		 */
		Shader* GetShaderAt(unsigned int pPos);
		/**
		 * @brief Get a pointer to the texture object at a given position
		 * 
		 * @param pPos The position in the array of the texture
		 * @return Texture* The pointer to the texture object
		 */
		Texture* GetTextureAt(unsigned int pPos);
		#pragma endregion

		Camera* m_cameraRef = nullptr;      // A reference to a camera
		unique_ptr<vector<unique_ptr<Mesh>>> m_meshes;
		unique_ptr<vector<unique_ptr<Shader>>> m_shaders;
		unique_ptr<vector<unique_ptr<Texture>>> m_textures;
		//Shader* m_shaderRef = nullptr;      // A reference to a shader
		//Texture* m_textureRef = nullptr;    // A reference to a texture

		Light* m_light = nullptr;
		LightDirectional* m_directionalLight = nullptr;

		const vec3 m_cubePositions[10] = {
			glm::vec3(0.0f,  0.0f,  0.0f),
			glm::vec3(2.0f,  5.0f, -15.0f),
			glm::vec3(-1.5f, -2.2f, -2.5f),
			glm::vec3(-3.8f, -2.0f, -12.3f),
			glm::vec3(2.4f, -0.4f, -3.5f),
			glm::vec3(-1.7f,  3.0f, -7.5f),
			glm::vec3(1.3f, -2.0f, -2.5f),
			glm::vec3(1.5f,  2.0f, -2.5f),
			glm::vec3(1.5f,  0.2f, -1.5f),
			glm::vec3(-1.3f,  1.0f, -1.5f)
		};
	};
}
