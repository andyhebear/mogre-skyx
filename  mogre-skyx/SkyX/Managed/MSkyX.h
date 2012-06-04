#pragma once

#include "MBasicController.h"
#include "MMoonManager.h"
#include "MVCloudsManager.h"
#include "MMeshManager.h"
#include "MGPUManager.h"
#include "MCloudsManager.h"
#include "MAtmosphereManager.h"

#include "SkyX.h"
#include "BasicController.h"

namespace SkyX {

public ref class MSkyX
{
public:

	/** Render queue groups
		 */
		value struct RenderQueueGroupsStruct
		{
			/** Constructor
			    Skydome render queue group
				VClouds render queue group
				VClouds lightnings render queue group
			 */
			inline RenderQueueGroupsStruct(const unsigned char& skydome, const unsigned char& vClouds, const unsigned char& vCloudsLightnings)
				: Skydome(skydome), VClouds(vClouds), VCloudsLightnings(vCloudsLightnings)
			{
			}

			/// Skydome render queue group
			unsigned char Skydome;
			/// VClouds render queue group
			unsigned char VClouds;
			/// VClouds lightnings render queue group
			unsigned char VCloudsLightnings;
		};

		/** Lighting mode enumeration
		    SkyX is designed for true HDR rendering, but there is a big number of applications
			which don't use HDR rendering, due to this fact a little exponential tone-mapping 
			algoritm is applied to SkyX materials if LM_LDR is selected. (See: AtmosphereManager::Options::Exposure)
			Select LM_HDR if your app is designed for true HDR rendering.
		 */
		enum class LightingModeEnum
		{
			/// Low dynamic range
			LowDynamicRange = 0,
			/// High dynamic range
			HighDynamicRange = 1
		};
		
	/** Contructor 
		    @param sm Ogre Scene manager
			@param c SkyX controller
		 */
		MSkyX(Mogre::SceneManager^ sceneManager, MBasicController^ mBasicController) {
			_SkyX = new SkyX((Ogre::SceneManager*)(void*)(sceneManager->NativePtr), (BasicController*)(mBasicController->NativePointer()));
			_Controller = mBasicController;
			_SceneManager = sceneManager;

			// Wrap all of the unmanaged managers (no punn intended) :)
			_MoonManager = gcnew MMoonManager(_SkyX->getMoonManager());
			_VCloudsManager = gcnew MVCloudsManager(_SkyX->getVCloudsManager());
			_MeshManager = gcnew MMeshManager(_SkyX->getMeshManager());
			_GPUManager = gcnew MGPUManager(_SkyX->getGPUManager());
			_CloudsManager = gcnew MCloudsManager(_SkyX->getCloudsManager());
			_AtmosphereManager = gcnew MAtmosphereManager(_SkyX->getAtmosphereManager());
		}

		/** Controller 
		 */
		property MBasicController^ Controller
		{
    		MBasicController^ get() { 
				return _Controller;
			}
			void set(MBasicController^ value)
			{
				_SkyX->setController((BasicController*)(value->NativePointer()));
				_Controller = value;
			}
		}

		/** Destructor 
		 */
		inline ~MSkyX(){
			delete _SkyX;
		}

		/** Create SkyX
         */
        inline void Create(){
			_SkyX->create();
		}

		/** Remove SkyX (free resources)
		 */
		inline void Remove(){
			_SkyX->remove();
		}

		/** 
		    Render target viewport event
		 */
		inline void OnPreViewportUpdate(Mogre::Viewport^ viewport) {
			//Mogre::Viewport vp = (Mogre::Viewport)viewport;
			Ogre::RenderTargetViewportEvent *evt = new Ogre::RenderTargetViewportEvent();
			evt->source = (Ogre::Viewport*)viewport->NativePtr;
			_SkyX->preViewportUpdate(*evt);
			delete evt;
		}

		/** 
		    Frame event
		 */
		inline bool OnFrameStarted(Mogre::FrameEvent m_evt) {
			Ogre::FrameEvent *evt = new Ogre::FrameEvent();
			evt->timeSinceLastEvent = m_evt.timeSinceLastEvent;
			evt->timeSinceLastFrame = m_evt.timeSinceLastFrame;
			bool retval = _SkyX->frameStarted(*evt);
			delete evt;
			return retval;
		}

		/** Notify camera render (to be invoked per camera and per frame)
		    @param c Camera
			@remarks Invoke this method manually before the camera render operation
				     Per-camera updates must be performed after the per-frame update through SkyX::update(...)
			         Also it's possible to use listeners, making all this process transparent,
					 just register SkyX in your render target through Ogre::RenderTarget::addListener(...)
		 */
		void OnNotifyCameraRender(Mogre::Camera c) {
			_SkyX->notifyCameraRender((Ogre::Camera*)c.NativePtr);
		}

        /** Update (to be invoked per frame)
		    @param timeSinceLastFrame Time elapsed since last frame
            @remarks Invoke this function only one time per frame.
					 Per-frame update must be performed before per-camera updates through SkyX::notifyCameraRender(...)
			         Also it's possible to use listeners, making all this process transparent,
					 just register SkyX in ogre root through Ogre::Root::addFrameListener(...)
         */
        inline void Update(float elapsedTimeInSeconds){
			_SkyX->update(elapsedTimeInSeconds);
		}
		
		/** Is SkyX created?
		    @return true if yes, false if not
		 */
		property bool IsCreated
		{
			bool get(){
				return _SkyX->isCreated();
			}
		}
		
		/** 
		    visible true to set SkyX visible, false to hide it
		 */
		property bool Visible
		{
    		bool get() { 
				return _SkyX->isVisible();
			}
			void set(bool value)
			{
				_SkyX->setVisible(value);
			}
		}
		
		/** 
		    @param TimeMultiplier Time multiplier
			@remarks The time multiplier can be a negative number, 0 will disable auto-updating
			         For setting a custom time of day, check: AtmosphereManager::Options::Time
		 */
		property float TimeMultiplier
		{
    		float get() { 
				return _SkyX->getTimeMultiplier();
			}
			void set(float value)
			{
				_SkyX->setTimeMultiplier(value);
			}
		}
		
		/** 
		    Enabled true for starfield, false for not
		 */
		property bool StarfieldEnabled
		{
    		bool get() { 
				return _SkyX->isStarfieldEnabled();
			}
			void set(bool value)
			{
				_SkyX->setStarfieldEnabled(value);
			}
		}
		
		/** 
		    @param d Infinite camera far clip distance
			@remarks SkyX needs a finite camera far clip distance in order to builds its geometry. Since Ogre allows infinite far clip
			         camera distances (camearFarClipDistance = 0) you'll need to manually provide a far clip distance if you're using
					 an infinite camera far clip distance.
		 */
		property float InfiniteCameraFarClipDistance
		{
    		float get() { 
				return _SkyX->getInfiniteCameraFarClipDistance();
			}
			void set(float value)
			{
				_SkyX->setInfiniteCameraFarClipDistance(value);
			}
		}

		/** Set lighting mode
		    @param lm Lighting mode
			@remarks SkyX is designed for true HDR rendering, but there're a lot of applications
			that doesn't use HDR rendering, due to this a little exponential tone-mapping 
			algoritm is applied to SkyX materials if LM_LDR is selected. (See: AtmosphereManager::Options::Exposure)
			Select LM_HDR if your app is designed for true HDR rendering.
		 */
		property LightingModeEnum^ LightingMode
		{
    		LightingModeEnum^ get() { 
				return *(LightingModeEnum*)&_SkyX->getLightingMode();
			}
			void set(LightingModeEnum^ value)
			{
				_SkyX->setLightingMode(*(SkyX::LightingMode*)&value);
			}
		}

		/** 
		Current render queue groups
		 */
		property RenderQueueGroupsStruct^ RenderQueueGroups
		{
    		RenderQueueGroupsStruct^ get() { 
				return *(RenderQueueGroupsStruct*)&_SkyX->getRenderQueueGroups();
			}
			void set(RenderQueueGroupsStruct^ value)
			{
				_SkyX->setRenderQueueGroups(*(SkyX::RenderQueueGroups*)&value);
			}
		}

		property MMoonManager^ MoonManager
		{
    		MMoonManager^ get() { 
				return _MoonManager;
			}
		};

		property MVCloudsManager^ VCloudsManager
		{
    		MVCloudsManager^ get() { 
				return _VCloudsManager;
			}
		};

		property MMeshManager^ MeshManager
		{
    		MMeshManager^ get() { 
				return _MeshManager;
			}
		};

		property MGPUManager^ GPUManager
		{
    		MGPUManager^ get() { 
				return _GPUManager;
			}
		};

		property MCloudsManager^ CloudsManager
		{
    		MCloudsManager^ get() { 
				return _CloudsManager;
			}
		};

		property MAtmosphereManager^ AtmosphereManager
		{
    		MAtmosphereManager^ get() { 
				return _AtmosphereManager;
			}
		};

		property Mogre::SceneManager^ SceneManager
		{
    		Mogre::SceneManager^ get() { 
				return _SceneManager;
			}
		};

	//TODO: Wrap this
		///** Get current rendering camera
		//    @return Current rendering camera
		// */
		//inline Ogre::Camera* getCamera()
		//{
		//    return mCamera;
		//}
		
		inline void* NativePointer() {
			return (void*)_SkyX;
		}

private:
	SkyX* _SkyX;
	MBasicController^ _Controller;
	Mogre::SceneManager^ _SceneManager;
	MMoonManager^ _MoonManager;
	MVCloudsManager^ _VCloudsManager;
	MMeshManager^ _MeshManager;
	MGPUManager^ _GPUManager;
	MCloudsManager^ _CloudsManager;
	MAtmosphereManager^ _AtmosphereManager;
}
;
}