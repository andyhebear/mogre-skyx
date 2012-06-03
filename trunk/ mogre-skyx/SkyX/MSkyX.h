#pragma once

#include "skyx.h"
#include "MBasicController.h"
#include "BasicController.h"

namespace SkyX {

public ref class MSkyX
{
public:
	/** Contructor 
		    @param sm Ogre Scene manager
			@param c SkyX controller
		 */
		MSkyX(Mogre::SceneManager^ sceneManager, MBasicController^ mBasicController) {
			_SkyX = new SkyX((Ogre::SceneManager*)(void*)(sceneManager->NativePtr), (BasicController*)(mBasicController->NativePointer()));
			_Controller = mBasicController;
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
			evt->source = (Ogre::Viewport*)(void*)viewport->NativePtr;
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
			_SkyX->notifyCameraRender((Ogre::Camera*)(void*)c.NativePtr);
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
		
		///** Get mesh manager
		//    @return Mesh manager pointer
		// */
		//inline MeshManager* getMeshManager()
		//{
		//	return mMeshManager;
		//}

		///** Get atmosphere manager
		//    @return Atmosphere manager pointer
		// */
		//inline AtmosphereManager* getAtmosphereManager()
		//{
		//	return mAtmosphereManager;
		//}

		///** Get GPU manager
		//    @return Atmosphere manager pointer
		// */
		//inline GPUManager* getGPUManager()
		//{
		//	return mGPUManager;
		//}

		///** Get moon manager
		//    @return Moon manager
		// */
		//inline MoonManager* getMoonManager()
		//{
		//	return mMoonManager;
		//}

		///** Get clouds manager
		//    @return Clouds manager
		// */
		//inline CloudsManager* getCloudsManager()
		//{
		//	return mCloudsManager;
		//}

		///** Get volumetric clouds manager
		//    @return Volumetric clouds manager
		// */
		//inline VCloudsManager* getVCloudsManager()
		//{
		//	return mVCloudsManager;
		//}

		///** Set render queue groups
		//    @param rqg Render queue groups
		// */
		//void setRenderQueueGroups(const RenderQueueGroups& rqg);

		///** Get render queue groups
		//    @return Current render queue groups
		// */
		//inline const RenderQueueGroups& getRenderQueueGroups() const
		//{
		//	return mRenderQueueGroups;
		//}

		///** Set lighting mode
		//    @param lm Lighting mode
		//	@remarks SkyX is designed for true HDR rendering, but there're a lot of applications
		//	that doesn't use HDR rendering, due to this a little exponential tone-mapping 
		//	algoritm is applied to SkyX materials if LM_LDR is selected. (See: AtmosphereManager::Options::Exposure)
		//	Select LM_HDR if your app is designed for true HDR rendering.
		// */
		//void setLightingMode(const LightingMode& lm);

		///** Get lighting mode
		//    @return Lighting mode
		// */
		//inline const LightingMode& getLightingMode() const
		//{
		//	return mLightingMode;
		//}

		/** Set the starfield enabled/disabled
		    @param Enabled true for starfield, false for not
		 */
		inline void setStarfieldEnabled(bool Enabled){
			_SkyX->setStarfieldEnabled(Enabled);
		}

		/** Is the starfield enable?
		    @return true if the starfield is enabled, false if it isn't
		 */
		inline bool isStarfieldEnabled() 
		{
			return _SkyX->isStarfieldEnabled();
		}

		/** Set infinite camera far clip distance
		    @param d Infinite camera far clip distance
			@remarks SkyX needs a finite camera far clip distance in order to builds its geometry. Since Ogre allows infinite far clip
			         camera distances (camearFarClipDistance = 0) you'll need to manually provide a far clip distance if you're using
					 an infinite camera far clip distance.
		 */
		inline void setInfiniteCameraFarClipDistance(float d)
		{
			_SkyX->setInfiniteCameraFarClipDistance(d);
		}

		/** Get infinite cmaera far clip distance
		    @return Infinite camera far clip distance
		 */
		inline float getInfiniteCameraFarClipDistance() 
		{
			return _SkyX->getInfiniteCameraFarClipDistance();
		}

		///** Get scene manager
		//    @return Ogre scene manager
		// */
		//inline Ogre::SceneManager* getSceneManager()
		//{
		//	return mSceneManager;
		//}

		///** Get current rendering camera
		//    @return Current rendering camera
		// */
		//inline Ogre::Camera* getCamera()
		//{
  //          return mCamera;
		//}
				

		inline void* NativePointer() {
			return (void*)_SkyX;
		}
private:
	SkyX* _SkyX;
	MBasicController^ _Controller;
};

}