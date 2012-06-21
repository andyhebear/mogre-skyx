#pragma once

#include "VClouds\VClouds.h"


namespace SkyX {

public ref class MVClouds
{
public:
	MVClouds(VClouds::VClouds* nativePointer){
		_Mgr = nativePointer;
	};
	
		/** Set wheater parameters
		    Use this funtion to update the cloud field parameters, you'll get a smart and smooth transition from your old 
			setting to your new ones.
			@param Humidity Humidity, in other words: the percentage of clouds in [0,1] range.
			@param AverageCloudsSize Average clouds size, for example: if previous wheater clouds size parameter was very different from new one(i.e: more little)
			       only the old biggest clouds are going to be keept and the little ones are going to be replaced
		    @param DelayedResponse false to change wheather conditions over several updates, true to change it at the moment
		 */
		inline void SetWeather(float Humidity, float AverageCloudsSize, bool DelayedResponse){
			_Mgr->setWheater(Humidity,AverageCloudsSize,DelayedResponse);
		}

private:
	VClouds::VClouds* _Mgr;
};

}
