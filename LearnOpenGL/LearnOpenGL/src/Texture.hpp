#pragma region 
#pragma once
#include <string>

using std::string;
#pragma endregion

namespace Engine
{
	enum class TexType : uint8_t
	{
		diffuse,
		specular
	};

	class Texture
	{
		friend class Model;
	public:
		Texture() {}
		Texture(const char* pPath, TexType pType);
		void Destroy();

		static void UnloadAll(bool pValidate);

		//void SetId(unsigned int pValue);
		//void SetType(TexType pValue);

		static unsigned int GetNumTex();
		unsigned int GetId() const;
		string GetType() const;
		
	private:
		/**
		 * @brief Loads an image from a file into vram (I'm assuming) as a texture
		 * 
		 * @param pPath The location of the image file
		 * @return uint8_t The ID for the texture (max 32 textures so this will be more than enough)
		 */
		static uint8_t LoadTexture(const char* pPath);

		static unsigned int s_idTex[32];	// List of all texture ids
		static unsigned int s_numTex;		// How many textures have been loaded

		unsigned int m_id = 0;
		TexType m_type = TexType::diffuse;
		string m_file;
	};
}
