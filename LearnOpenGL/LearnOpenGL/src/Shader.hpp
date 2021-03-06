#pragma region
#pragma once
#include <string>
#include <fstream>
#include "glm/glm.hpp"

using std::string;
#pragma endregion

namespace Engine
{
	enum class ShaderType : uint8_t
	{
		PROGRAM,
		VERTEX,
		FRAGMENT
	};

	class Shader
	{
	public:
		Shader();
		/**
		 * @brief Construct a new Shader object
		 *
		 * @param pVertexPath The file path to the vertex shader
		 * @param pFragmentPath The file path to the fragment shader
		 */
		Shader(string pShaderPath);

		#pragma region Copy constructors
		Shader(const Shader& pOther);
		Shader(Shader&& pOther) noexcept;
		Shader& operator=(const Shader& pOther);
		Shader& operator=(Shader&& pOther) noexcept;
		#pragma endregion

		~Shader() {}

		/**
		 * @brief Destroys the shader but only if it was ever initliased
		 *
		 * @param pValidate Whether the shader was even initialised
		 */
		void Destroy(bool pValidate);
		/**
		 * @brief Use/activate the shader
		 */
		void Use();
		void LoadPaths(string pShaderPath);

		bool GetLoaded() const { return m_shaderLoaded; }

	private:
		/**
		 * @brief Loads the shader code from file
		 * 
		 * @param pType The type of shader to load: VERTEX, FRAGMENT
		 */
		void LoadShader(ShaderType pType);
		/**
		 * @brief Compiles a specified shader
		 * 
		 * @param pId The shader id
		 * @param pType The type of shader to compile: VERTEX, FRAGMENT
		 * @param pCode The shader code
		 * @return If shader compilation was successful
		 */
		bool CompileShader(unsigned int* pId, ShaderType pType, const char* pCode);
		/**
		 * @brief Create a Shader Program object and link the vertex and fragment code
		 */
		void CreateShaderProgram();

		/**
		 * @brief Checks a shader for errors while loading and logs them
		 *
		 * @param pShaderID The id of the shader to be error checked
		 * @param pType The type of shader being error checked
		 * @return true if no error, false if error
		 */
		bool ShaderErrorChecking(unsigned int *pShaderID, ShaderType pType);

		bool m_shaderLoaded = false;
		unsigned int m_idProgram, m_idVertex, m_idFragment;
		string m_shaderPath;	// The file path of the shaders

		#pragma region Setters
	public:
		// Utility uniform functions
		/**
		 * @brief Assigns data to a bool uniform in the shader
		 *
		 * @param pName The name of the uniform
		 * @param pValue The value assigned to the uniform
		 */
		void SetBool(const string& pName, bool pValue) const;
		/**
		 * @brief Assigns data to a int uniform in the shader
		 *
		 * @param pName The name of the uniform
		 * @param pValue The value assigned to the uniform
		 */
		void SetInt(const string& pName, int pValue) const;
		/**
		 * @brief Assigns data to a uint uniform in the shader
		 * 
		 * @param pName The name of the uniform
		 * @param pValue The value assigned to the uniform
		 */
		void SetUint(const string& pName, unsigned int pValue) const;
		/**
		 * @brief Assigns data to a float uniform in the shader
		 *
		 * @param pName The name of the uniform
		 * @param pValue The value assigned to the uniform
		 */
		void SetFloat(const string& pName, float pValue) const;
		/**
		 * @brief Assigns data to a vec2 uniform in the shader
		 * 
		 * @param pName The name of the uniform
		 * @param pX The first value assigned to the uniform
		 * @param pY The second value assigned to the uniform
		 */
		void SetVec2(const string& pName, float pX, float pY) const;
		/**
		 * @brief Assigns data to a vec2 uniform in the shader
		 * 
		 * @param pName The name of the uniform
		 * @param pValue The value assigned to the uniform
		 */
		void SetVec2(const string& pName, glm::vec2 pValue) const;
		/**
		 * @brief Assigns data to a vec2 uniform in the shader
		 * 
		 * @param pName The name of the uniform
		 * @param pValue The value assigned to the uniform, passed by reference
		 */
		void SetVec2(const string& pName, glm::vec2& pValue) const;
		/**
		 * @brief Assigns data to a vec3 uniform in the shader
		 * 
		 * @param pName The name of the uniform
		 * @param pX The first value assigned to the uniform
		 * @param pY The second value assigned to the uniform
		 * @param pZ The third value assigned to the uniform
		 */
		void SetVec3(const string& pName, float pX, float pY, float pZ) const;
		/**
		 * @brief Assigns data to a vec3 uniform in the shader
		 * 
		 * @param pName The name of the uniform
		 * @param pValue The value assigned to the uniform
		 */
		void SetVec3(const string& pName, glm::vec3 pValue) const;
		/**
		 * @brief Assigns data to a vec3 uniform in the shader
		 * 
		 * @param pName The name of the uniform
		 * @param pValue The value assigned to the uniform, passed by reference
		 */
		void SetVec3(const string& pName, glm::vec3& pValue) const;
		/**
		 * @brief Assigns data to a vec4 uniform in the shader
		 * 
		 * @param pName The name of the uniform
		 * @param pX The first value assigned to the uniform
		 * @param pY The second value assigned to the uniform
		 * @param pZ The third value assigned to the uniform
		 * @param pW The fourth value assigned to the uniform
		 */
		void SetVec4(const string& pName, float pX, float pY, float pZ, float pW) const;
		/**
		 * @brief Assigns data to a vec4 uniform in the shader
		 * 
		 * @param pName The name of the uniform
		 * @param pValue The value assigned to the uniform
		 */
		void SetVec4(const string& pName, glm::vec4 pValue) const;
		/**
		 * @brief Set the Vec 4 object
		 * 
		 * @param pName The name of the uniform
		 * @param pValue The value assigned to the uniform, passed by reference
		 */
		void SetVec4(const string& pName, glm::vec4& pValue) const;
		/**
		 * @brief Assigns data to a mat3 uniform in the shader
		 * 
		 * @param pName The name of the uniform
		 * @param pValue The value assigned to the uniform
		 */
		void SetMat3(const string& pName, glm::mat3 pValue) const;
		/**
		 * @brief Assigns data to a mat3 uniform in the shader
		 * 
		 * @param pName The name of the uniform
		 * @param pValue The value assigned to the uniform, passed by reference
		 */
		void SetMat3(const string& pName, glm::mat3& pValue) const;
		/**
		 * @brief Assigns data to a mat4 uniform in the shader
		 *
		 * @param pName The name of the uniform
		 * @param pValue The value assigned to the uniform
		 */
		void SetMat4(const string& pName, glm::mat4 pValue) const;
		/**
		 * @brief Assigns data to a mat4 uniform in the shader
		 * 
		 * @param pName The name of the uniform
		 * @param pValue The value assigned to the uniform, passed by reference
		 */
		void SetMat4(const string& pName, glm::mat4& pValue) const;
		#pragma endregion
	};
}
