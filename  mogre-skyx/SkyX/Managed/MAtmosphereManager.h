#pragma once

#include "AtmosphereManager.h";

namespace SkyX {
public ref class MAtmosphereManager
{
public:

	MAtmosphereManager(AtmosphereManager* nativePointer)
	{
		_Mgr = nativePointer;
	}
		/** Atmosphere options 
		 */
		value struct OptionsStruct 
		{
			/// Inner atmosphere radius
			float InnerRadius;
			/// Outer atmosphere radius
			float OuterRadius;
			/// Height position, in [0, 1] range, 0=InnerRadius, 1=OuterRadius
			float HeightPosition;

			/// Rayleigh multiplier
			float RayleighMultiplier;
			/// Mie multiplier
			float MieMultiplier;
			/// Sun intensity
			float SunIntensity;

			/// WaveLength for RGB channels
			Mogre::Vector3^ WaveLength;

			/// Phase function
			float G;

			/// Exposure coeficient
			float Exposure;

			/// Number of samples
			int NumberOfSamples;

			//TODO: Wrap?
			///** Default constructor
			// */
			//OptionsStruct()
			//	: InnerRadius(9.77501f)
			//	, OuterRadius(10.2963f)
			//	, HeightPosition(0.01f)
			//	, RayleighMultiplier(0.0022f)
			//	, MieMultiplier(0.000675f)
			//	, SunIntensity(30)
			//	, WaveLength(gcnew Mogre::Vector3(0.57f, 0.54f, 0.44f))
			//	, G(-0.991f)
			//	, Exposure(2.0f)
			//	, NumberOfSamples(4)
			//{
			//}

			/** Constructor
                @param _InnerRadius Inner atmosphere radius
				@param _OuterRadius Outer atmosphere radius
				@param _HeightPosition Height position, in [0, 1] range, 0=InnerRadius, 1=OuterRadius
				@param _RayleighMultiplier Rayleigh multiplier
				@param _MieMultiplier Mie multiplier
				@param _SunIntensity Sun intensity
				@param _WaveLength Wave length for RGB channels
				@param _G Phase function
				@param _Exposure Exposure
				@param _NumerOfSamples Number of samples
			 */
			OptionsStruct(float	 _InnerRadius,
				    float	 _OuterRadius,
					float	 _HeightPosition,
					float	 _RayleighMultiplier,
					float	 _MieMultiplier,
					float    _SunIntensity,
					Mogre::Vector3^ _WaveLength,
					float    _G,
					float    _Exposure,
					int			 _NumerOfSamples)
				: InnerRadius(_InnerRadius)
				, OuterRadius(_OuterRadius)
				, HeightPosition(_HeightPosition)
				, RayleighMultiplier(_RayleighMultiplier)
				, MieMultiplier(_MieMultiplier)
				, SunIntensity(_SunIntensity)
				, WaveLength(_WaveLength)
				, G(_G)
				, Exposure(_Exposure)
				, NumberOfSamples(_NumerOfSamples)
			{
			}
		};

		/**  New options 
		 */
		property OptionsStruct^ Options
		{
    		OptionsStruct^ get() { 
				return *(OptionsStruct*)&_Mgr->getOptions();
			}
			void set(OptionsStruct^ value)
			{
				_Mgr->setOptions(*(AtmosphereManager::Options*)&value);
			}
		}

		/** Get current atmosphere color at the given direction
		    @param Direction *Normalised* direction
			@return Atmosphere color at the especified direction
		 */
		inline Mogre::Vector3^ GetColorAt(Mogre::Vector3^ direction) {
			return *((Mogre::Vector3*)&_Mgr->getColorAt(GetNativeVector(direction)));
		}

private:
	AtmosphereManager* _Mgr;

Ogre::Vector3 GetNativeVector(Mogre::Vector3^ input)
{
	return Ogre::Vector3(input->x,input->y,input->z);
};

};

}