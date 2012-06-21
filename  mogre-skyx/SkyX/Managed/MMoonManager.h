#pragma once

#include "MoonManager.h";

 namespace SkyX {
public ref class MMoonManager
{
public:

	MMoonManager(MoonManager* nativePointer)
	{
		_Mgr = nativePointer;
	}
	 ///** Constructor
		//    @param s Parent SkyX pointer
		// */
		//MoonManager(SkyX *s);

		///** Destructor 
		// */
		//~MoonManager();

		///** Create all resources
		// */
		//void create();

		///** Remove all resources
		// */
		//void remove();

		///** Update moon phase
		//    @param phase Moon phase in [-1,1] range, where -1 means fully covered Moon, 0 clear Moon and 1 fully covered Moon
		// */
		//void updateMoonPhase(const Ogre::Real& phase);

		///** Update geometry
		//    @param c Camera
		// */
		//void updateGeometry(Ogre::Camera* c);
	
		///** Get moon billboard
		//    @return Moon billboard
		// */
		//inline Ogre::BillboardSet* getMoonBillboard()
		//{
		//	return mMoonBillboard;
		//}

		///** Get moon scene node
		//    @return Moon scene node
		// */
		//inline Ogre::SceneNode* getMoonSceneNode()
		//{
		//	return mMoonSceneNode;
		//}

		/**
		    Moon size
		 */
		property float MoonSize
		{
			float get()
			{
				return _Mgr->getMoonSize();
			}
        
			void set(float value)
			{
				_Mgr->setMoonSize(value);
			}
		}

		/**
		    Moon halo intensity
		 */
		property float MoonHaloIntensity
		{
			float get()
			{
				return _Mgr->getMoonHaloIntensity();
			}
        
			void set(float value)
			{
				_Mgr->setMoonHaloIntensity(value);
			}
		}

		/**
		    Moon halo strength
		 */
		property float MoonHaloStrength
		{
			float get()
			{
				return _Mgr->getMoonHaloStrength();
			}
        
			void set(float value)
			{
				_Mgr->setMoonHaloStrength(value);
			}
		}

		/** Is created?
		    @return true if yes, false if not
		 */
		property bool IsCreated
		{
			bool get(){
				return _Mgr->isCreated();
			}
		}
private:
	MoonManager* _Mgr;
};
}
