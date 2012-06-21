#pragma once

#include "MColorFrame.h";
#include "ColorGradient.h";

namespace SkyX
{
public ref class MColorFrame
{
public:
	MColorFrame(ColorGradient::ColorFrame* nativePointer) {
		_Internal = nativePointer;
	}

	MColorFrame(Mogre::Vector3^ color, float position)
	{
		_Internal= new ColorGradient::ColorFrame();
		this->Position = position;
		this->Color = color;
	}

	property Mogre::Vector3^ Color
		{
			Mogre::Vector3^ get()
			{
				return *((Mogre::Vector3*)&_Internal->first);
			}
        
			void set(Mogre::Vector3^ value)
			{
				_Internal->first = GetNativeVector(value);
			}
		}

	property float Position
		{
			float get()
			{
				return _Internal->second;
			}
        
			void set(float value)
			{
				_Internal->second = value;
			}
		}

		inline void* NativePointer() {
			return (void*)_Internal;
		}

private:
	ColorGradient::ColorFrame* _Internal;

Ogre::Vector3 GetNativeVector(Mogre::Vector3^ input)
{
	return Ogre::Vector3(input->x,input->y,input->z);
};

};

}