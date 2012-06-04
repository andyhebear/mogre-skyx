#pragma once

#include "MoonManager.h";

namespace SkyX {
ref class MMoonManager
{
public:

	MMoonManager(void* nativePointer)
	{
		_Mgr = (MoonManager*)&nativePointer;
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

		///** Set moon size
		//    @param MoonSize Moon size
		// */
		//inline void setMoonSize(const Ogre::Real& MoonSize)
		//{
		//	mMoonSize = MoonSize;
		//}

		///** Get moon size
		//    @return Moon size
		// */
		//inline const Ogre::Real& getMoonSize() const
		//{
		//	return mMoonSize;
		//}

		///** Set moon halo intensity
		//    @param MoonHaloIntensity Moon halo intensity
		// */
		//inline void setMoonHaloIntensity(const Ogre::Real& MoonHaloIntensity)
		//{
		//	mMoonHaloIntensity = MoonHaloIntensity;
		//}

		///** Get moon halo intensity
		//    @return Moon halo intensity
		// */
		//inline const Ogre::Real& getMoonHaloIntensity() const
		//{
		//	return mMoonHaloIntensity;
		//}

		///** Set moon halo strength
		//    @param MoonHaloStrength Moon halo strength (linear/exponential fading)
		// */
		//inline void setMoonHaloStrength(const Ogre::Real& MoonHaloStrength)
		//{
		//	mMoonHaloStrength = MoonHaloStrength;
		//}

		///** Get moon halo strength
		//    @return Moon halo strength (linear/exponential fading)
		// */
		//inline const Ogre::Real& getMoonHaloStrength() const
		//{
		//	return mMoonHaloStrength;
		//}

		///** Is moon manager created?
		//    @return true if yes, false if not
		// */
		//inline const bool& isCreated() const
		//{
		//	return mCreated;
		//}

private:
	MoonManager* _Mgr;
};
}
