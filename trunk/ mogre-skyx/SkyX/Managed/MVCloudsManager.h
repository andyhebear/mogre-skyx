#pragma once

#include "VCloudsManager.h";
#include "MColorGradient.h";
#include "MVClouds.h";

namespace SkyX {
public ref class MVCloudsManager
{
public:

	MVCloudsManager(VCloudsManager* nativePointer)
	{
		_Mgr = nativePointer;
	}

		/** Destructor 
		 */
		~MVCloudsManager(){
			delete _Mgr;
		}

		/** Create all resources
		    @param radius Volumetric cloud field radius, -1 to use current VClouds::mGeometrySettings::Radius
		 */
		void Create(){
			_Mgr->create(-1);
		}

	//	/** Update
	//	    @param timeSinceLastFrame Time since last frame
	//	 */
	//	void update(const Ogre::Real& timeSinceLastFrame);

	//	/** Notify camera render, to be invoked per-camera and per-frame
	//		@param c Rendering camera
	//		@remarks The VClouds system needs the CAMERA time since last frame, so here we assume that all render targets
	//		         are being updated one time per frame(in other words, all render targets are being updated at the same rate)
 //        */
 //       void notifyCameraRender(Ogre::Camera* c);

		/** Remove all resources
		 */
		void Remove() {
			_Mgr->remove();
		}

	/** Set height parameters
		    @param Height x = Cloud field y-coord start, y: Field height (both in world coordinates)
			@remarks Call it before create(), for now...
			         For autocalculated height based on the radius length set (-1,-1) as height params
	*/
	property MColorGradient^ AmbientGradient
		{
			MColorGradient^ get()
			{
				return gcnew MColorGradient(_Mgr->getAmbientGradient());
			}
        
			void set(MColorGradient^ value)
			{
				_Mgr->setAmbientGradient(*(ColorGradient*)value->NativePointer());
			}
	}
	/**
	 Sun color gradient
	*/
	property MColorGradient^ SunGradient
		{
			MColorGradient^ get()
			{
				return gcnew MColorGradient(_Mgr->getSunGradient());
			}
        
			void set(MColorGradient^ value)
			{
				_Mgr->setSunGradient(*(ColorGradient*)value->NativePointer());
			}
	}

	/** Set height parameters
		    @param Height x = Cloud field y-coord start, y: Field height (both in world coordinates)
			@remarks Call it before create(), for now...
			         For autocalculated height based on the radius length set (-1,-1) as height params
	*/
	property Mogre::Vector2^ Height
		{
			Mogre::Vector2^ get()
			{
				return *((Mogre::Vector2*)&_Mgr->getHeight());
			}
        
			void set(Mogre::Vector2^ value)
			{
				_Mgr->setHeight(GetNativeVector2(value));
			}
		}
		

	//	/** Set autoupdate
	//	    @Autoupdate true if you want to update volumetric clouds wind depending of the SkyX time multiplier
	//		@remarks You can use VClouds->setWindSpeed(..) for different winds speeds
	//	 */
	property bool AutoUpdate
		{
			bool get()
			{
				return _Mgr->getAutoupdate();
			}
        
			void set(bool value)
			{
				_Mgr->setAutoupdate(value);
			}
	}


	//	/** Set wind speed
	//	    @param WindSpeed Wind speed
	//	 */
	property float WindSpeed
		{
			float  get()
			{
				return _Mgr->getWindSpeed();
			}
        
			void set(float  value)
			{
				_Mgr->setWindSpeed(value);
			}
	}

		/** Get VClouds
		 */
		inline MVClouds^ VClouds()
		{
			if (_VClouds == nullptr) {
				_VClouds = gcnew MVClouds(_Mgr->getVClouds());
			}
			return _VClouds;
		}

	//	/** Is created?
	//	   true if yes, false if not
	//	 */
	property bool Created
		{
			bool get()
			{
				return _Mgr->isCreated();
			}        
	}

private:
	VCloudsManager* _Mgr;
	MVClouds^ _VClouds;
	
	
	Ogre::Vector3 GetNativeVector(Mogre::Vector3^ input)
	{
		return Ogre::Vector3(input->x,input->y,input->z);
	};
	
	Ogre::Vector2 GetNativeVector2(Mogre::Vector2^ input)
	{
		return Ogre::Vector2(input->x,input->y);
	};
};
}
