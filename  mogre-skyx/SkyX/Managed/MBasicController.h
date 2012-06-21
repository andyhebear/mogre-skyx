#pragma once

#include "BasicController.h"

namespace SkyX {
	public ref class MBasicController
	{
	public:
		inline MBasicController(bool deleteBySkyX){
			_BasicController = new BasicController(deleteBySkyX);
		}

		inline ~MBasicController(){
			delete _BasicController;
		}

		/** Update controller
		    @param simDeltaTime Simulation delta time (It's not the time since last frame, it's the delta simulation time, one
								time the time since last frame has been multiplied by the time multiplier)
		 */
		inline void Update(float elapsedTimeInSeconds){
			_BasicController->update(elapsedTimeInSeconds);
		}

		/**
		Time, where x = time in [0, 24]h range, y = sunrise hour in [0, 24]h range, z = sunset hour in [0, 24] range
		*/
		property Mogre::Vector3^ Time
		{
			Mogre::Vector3^ get()
			{
				return *((Mogre::Vector3*)&_BasicController->getTime());
			}
        
			void set(Mogre::Vector3^ value)
			{
				_BasicController->setTime(GetNativeVector(value));
			}
		}

		/** 
		    East direction, in X,Z world coords (must be normalized)
		 */
		property Mogre::Vector2^ EastDirection
		{
			Mogre::Vector2^ get()
			{
				return *((Mogre::Vector2*)&_BasicController->getEastDirection());
			}
        
			void set(Mogre::Vector2^ value)
			{
				_BasicController->setEastDirection(*(Ogre::Vector2*)&value);
			}
		}


		/** 
		    Sun direction, the Earth-to-Sun direction
		 */
		property Mogre::Vector3^ SunDirection
		{
			Mogre::Vector3^ get()
			{
				return *((Mogre::Vector3*)&_BasicController->getSunDirection());
			}
		}
		
		/** 
		    Moon direction, Earth-to-Moon direction
		 */
		property Mogre::Vector3^ MoonDirection
		{
			Mogre::Vector3^ get()
			{
				return *((Mogre::Vector3*)&_BasicController->getMoonDirection());
			}
		}
				
		/** 
		    Moon phase in [-1,1] range, where -1 means fully covered Moon, 0 clear Moon and 1 fully covered Moon
		 */
		property float MoonPhase
		{
			float get()
			{
				return _BasicController->getMoonPhase();
			}
        
			void set(float value)
			{
				_BasicController->setMoonPhase(value);
			}
		}


		inline void* NativePointer() {
			return (void*)_BasicController;
		}
private:
		BasicController *_BasicController;

Ogre::Vector3 GetNativeVector(Mogre::Vector3^ input)
{
	return Ogre::Vector3(input->x,input->y,input->z);
};

	};

}