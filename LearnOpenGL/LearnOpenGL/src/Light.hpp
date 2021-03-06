#pragma once
#include "Transform.hpp"

namespace Engine
{
	enum class LightType : uint8_t
	{
		Directional,
		Point,
		Spot
	};

	class Light : public Transform
	{
	public:
		#pragma region Constructors
		Light(LightType pType);										// Generic
		Light(LightType pType, mat4 pTransform);					// Generic
		Light(LightType pType, mat4 pTransform, vec3 pColour);		// Generic
		Light(LightType pType, vec3 pDirection);					// Directional
		Light(LightType pType, vec3 pDirection, vec3 pColour);		// Directional
		Light(LightType pType, vec4 pPosition);						// Point
		Light(LightType pType, vec4 pPosition, vec3 pColour);		// Point
		Light(LightType pType, mat4 pTransform, float pAngle, float pBlur);									// Spot
		Light(LightType pType, mat4 pTransform, vec3 pColour, float pAngle, float pBlur);					// Spot
		Light(LightType pType, vec4 pPosition, vec3 pDirection, vec3 pColour, float pAngle, float pBlur);	// Spot
		~Light() {}
		#pragma endregion
		#pragma region Setters
		void SetColour(vec3 pColour);
		void SetAngle(float pValue);
		void SetBlur(float pValue);
		#pragma endregion
		#pragma region Getters
		LightType GetType() const;
		vec4 GetDirection() const;
		vec3 GetColour() const;
		float GetAngle();
		float GetAngleRaw() const;
		float GetBlur();
		float GetBlurRaw() const;
		#pragma endregion

	private:
		LightType m_type;
		vec3 m_lightColour;
		float m_angle;		// Only for spotlights
		float m_blur;		// Only for spotlights
	};
}
