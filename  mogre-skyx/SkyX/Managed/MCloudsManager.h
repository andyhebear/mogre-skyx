#pragma once

#include "CloudsManager.h";

namespace SkyX {
public ref class MCloudLayer
{
public:

	MCloudLayer(CloudLayer* nativePointer)
	{
		_Mgr = nativePointer;
	}

	/** Cloud layer options 
		 */
		value struct OptionsStruct
		{
			/// Cloud layer height
			float Height;
			/// Cloud layer scale
			float Scale;
			/// Wind direction
			Mogre::Vector2^ WindDirection;
			/// Time multiplier
			float TimeMultiplier;

			/// Distance attenuation
			float DistanceAttenuation;
			/// Detail attenuation
			float DetailAttenuation;
			/// Cloud layer height volume(For volumetric effects on the gpu)
			float HeightVolume;
			/// Volumetric displacement(For volumetric effects on the gpu)
			float VolumetricDisplacement;

			//TODO: Wrap?
			///** Default constructor
			// */
			//OptionsStruct()
			//	: Height(100)
			//	, Scale(0.001f)
			//	, WindDirection(gcnew Mogre::Vector2(1,1))
			//	, TimeMultiplier(0.125f)
			//	, DistanceAttenuation(0.05f)
			//	, DetailAttenuation(1)
			//	, HeightVolume(0.25f)
			//	, VolumetricDisplacement(0.01f)
			//{
			//}

			/** Constructor
			    @param _Height Cloud layer height
				@param _Scale Clouds scale
				@param _WindDirection Clouds movement direction
				@param _TimeMultiplier Time multiplier factor
			 */
			OptionsStruct(float _Height, 
				    float _Scale, 
					Mogre::Vector2^ _WindDirection, 
					float _TimeMultiplier)
				: Height(_Height)
				, Scale(_Scale)
				, WindDirection(_WindDirection)
				, TimeMultiplier(_TimeMultiplier)
				, DistanceAttenuation(0.05f)
				, DetailAttenuation(1)
				, HeightVolume(0.25f)
				, VolumetricDisplacement(0.01f)
			{
			}

			/** Constructor
			    @param _Height Cloud layer height
				@param _Scale Clouds scale
				@param _WindDirection Clouds movement direction
				@param _TimeMultiplier Time multiplier factor
				@param _DistanceAttenuation Distance attenuation
				@param _DetailAttenuation Detail attenuation
				@param _HeightVolume Height volume(For volumetric effects on the gpu)
				@param _VolumetricDisplacement Volumetric displacement(For volumetric effects on the gpu)
				
			 */
			OptionsStruct(float _Height, 
				    float _Scale, 
					Mogre::Vector2^ _WindDirection, 
					float _TimeMultiplier,
					float _DistanceAttenuation,
					float _DetailAttenuation,
					float _HeightVolume,
					float _VolumetricDisplacement)
				: Height(_Height)
				, Scale(_Scale)
				, WindDirection(_WindDirection)
				, TimeMultiplier(_TimeMultiplier)
				, DistanceAttenuation(_DistanceAttenuation)
				, DetailAttenuation(_DetailAttenuation)
				, HeightVolume(_HeightVolume)
				, VolumetricDisplacement(_VolumetricDisplacement)
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
				_Mgr->setOptions(*(CloudLayer::Options*)&value);
			}
		}
				
		//// TODO: Wrap
		///** Set ambient gradient
		//    @param AmbientGradient Ambient color gradient
		// */
		//inline void setAmbientGradient(const ColorGradient& AmbientGradient)
		//{
		//	mAmbientGradient = AmbientGradient;
		//}

		///** Get ambient color gradient
		//    @return Ambient color gradient
		// */
		//inline const ColorGradient& getAmbientGradient() const
		//{
		//	return mAmbientGradient;
		//}
		///** Set sun gradient
		//    @param SunGradient Sun color gradient
		// */
		//inline void setSunGradient(const ColorGradient& SunGradient)
		//{
		//	mSunGradient = SunGradient;
		//}
		///** Get sun color gradient
		//    @return Sun color gradient
		// */
		//inline const ColorGradient& getSunGradient() const
		//{
		//	return mSunGradient;
		//}
private:
	CloudLayer* _Mgr;
};

ref class MCloudsManager
{
public:

	MCloudsManager(void* nativePointer)
	{
		_Mgr = (CloudsManager*)&nativePointer;
	}
		///** Constructor
		//    @param s SkyX parent pointer
		// */
		//CloudsManager(SkyX *h);

		///** Destructor
		// */
  //      ~CloudsManager();

		///** Update cloud layers
		// */
		//void update();

		///** Add a cloud layer
		//    @param o Cloud layer options
		//	@return Cloud layer
		// */
		//CloudLayer* add(const CloudLayer::Options& o);

		///** Remove the specified cloud layer
		// */
		//void remove(CloudLayer *cl);

		///** Remove all cloud layers
		// */
		//void removeAll();

		///** Register all
		// */
		//void registerAll();

		///** Unregister cloud layer
		//    @param cl Cloud layer to be unregistered
		// */
		//void unregister(CloudLayer* cl);

		///** Unregister all cloud layers
		// */
		//void unregisterAll();

		///** Get cloud layers
		//    @return Cloud layers
		// */
		//inline const std::vector<CloudLayer*>& getCloudLayers() const
		//{
		//	return mCloudLayers;
		//}
private:
	CloudsManager* _Mgr;
};

}