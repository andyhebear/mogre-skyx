#pragma once

#include "MeshManager.h";

namespace SkyX {
public ref class MMeshManager
{
public:

	MMeshManager(MeshManager* nativePointer)
	{
		_Mgr = nativePointer;
	}
	///** Vertex struct
	//	 */
	//	struct VERTEX
	//	{
	//		      // Position
	//		float x, y, z,
	//		      // Normalized position
	//		      nx, ny, nz,
	//			  // Texture coords
	//		      u, v,
	//			  // Opacity
	//			  o;
	//	};

	//	/** Constructor
	//	    @param s Parent SkyX pointer
	//	 */
	//	MeshManager(SkyX *s);

	//	/** Destructor 
	//	 */
	//	~MeshManager();

	//	/** Create our water mesh, geometry, entity, etc...
 //           @remarks Call it after setMaterialName()
 //        */
 //       void create();

	//	/** Remove all resources
	//	 */
	//	void remove();

	//	/** Update geometry
	//	    @param cam Camera
	//	 */
	//	void updateGeometry(Ogre::Camera* cam);

	//	/** Get mesh
 //           @return Mesh
 //        */
 //       inline Ogre::MeshPtr getMesh()
 //       {
 //           return mMesh;
 //       }

 //       /** Get sub mesh
 //           @return Sub mesh
 //        */
 //       inline Ogre::SubMesh* getSubMesh()
 //       {
 //           return mSubMesh;
 //       }

 //       /** Get entity
 //           @return Entity
 //        */
 //       inline Ogre::Entity* getEntity()
 //       {
 //           return mEntity;
 //       }

 //       /** Get material name
 //           @return Material name
 //        */
 //       inline const Ogre::String& getMaterialName() const
 //       {
 //           return mMaterialName;
 //       }

	//	/** Set mesh material
 //           @param MaterialName The material name
 //        */
 //       void setMaterialName(const Ogre::String &MaterialName);

	//	/** Get hardware vertex buffer reference
 //           @return Ogre::HardwareVertexBufferSharedPtr reference
 //        */
 //       inline Ogre::HardwareVertexBufferSharedPtr &getHardwareVertexBuffer()
 //       {
 //           return mVertexBuffer;
 //       }

	//	/** Get hardware index buffer reference
	//	    @return Ogre::HardwareIndexBufferSharedPtr reference
	//	 */
	//	inline Ogre::HardwareIndexBufferSharedPtr &getHardwareIndexBuffer()
	//	{
	//		return mIndexBuffer;
	//	}

	//	/** Get the Ogre::SceneNode pointer where Hydrax mesh is attached
	//	    @return Ogre::SceneNode*
	//	 */
	//	inline Ogre::SceneNode* getSceneNode()
	//	{
	//		return mSceneNode;
	//	}

	//	/** Is _createGeometry() called?
	//	    @return true if created() have been already called
	//	 */
	//	inline const bool& isCreated() const
	//	{
	//		return mCreated;
	//	}

	//	/** Set geometry parameters
	//	    @param Steps Sphere number of steps
	//		@param Circles Spehere number of circes
	//	 */
	//	void setGeometryParameters(const int& Steps, const int& Circles);

	//	/** Get number of steps
	//	    @return Number of steps
	//	 */
	//	inline const int& getSteps() const
	//	{
	//		return mSteps;
	//	}

	//	/** Get number of circles
	//	    @return Number of circles
	//	 */
	//	inline const int& getCircles() const
	//	{
	//		return mCircles;
	//	}

	//	/** Set under-horizon rendering params
	//	    @remarks In an ideal situation, you only must see the avobe horizon sky due to the fact that the terrain/water
	//		         must be 'infinite' and the under-horizont sky part is hide.
	//				 But, infinite terrain/water is not always implemented in games and 3d apps in general, so... in order to
	//				 get a good-looking sky, SkyX provides an approach to render realistic under-horizont sky.
	//		@param UnderHorizonCircles Number of circles of SkyX::MeshManager::mCircles reserved for the under-horizont geometry part,
	//			   0 means not under-horizon rendering
	//		@param UnderHorizonFading true/false to fade or not the under-horizon sky
	//		@param UnderHorizonFadingExponent Exponent of the fading, pow(vertex_angle, exp), 1=linear
	//		@param UnderHorizonFadingMultiplier Fading multiplier, opacity = saturate(pow(opacity,fading_exp)*fading_multiplier)
	//	 */
	//	void setUnderHorizonParams(const int& UnderHorizonCircles = 15, const bool& UnderHorizonFading = true, const Ogre::Real& UnderHorizonFadingExponent = 1, const Ogre::Real& UnderHorizonFadingMultiplier = 2);

	//	/** Get under-horizon circles
	//	    @return Under-horizon circles
	//	 */
	//	inline const int& getUnderHorizonCircles() const
	//	{
	//		return mUnderHorizonCircles;
	//	}

	//	/** Get under-horizon fading
	//	    @return Under-horizon fading
	//	 */
	//	inline const bool& getUnderHorizonFading() const
	//	{
	//		return mUnderHorizonFading;
	//	}

	//	/** Get under-horizon exponent fading
	//	    @return under-horizon exponent fading
	//     */
	//	inline const Ogre::Real& getUnderHorizonFadingExponent() const
	//	{
	//		return mUnderHorizonFadingExponent;
	//	}

	//	/** Get under-horizon fading multiplier
	//	    @return Under-horizon fading multiplier
	//	 */
	//	inline const Ogre::Real& getUnderHorizonFadingMultiplier() const
	//	{
	//		return mUnderHorizonFadingMultiplier;
	//	}

	//	/** Set radius multiplier
	//	    @param RadiusMultiplier Radius multiplier
	//		@remarks Radius multiplier in [0,1] range
	//		         Radius = CameraFarClipDistance * RadiusMultiplier
	//	 */
	//	inline void setRadiusMultiplier(const Ogre::Real& RadiusMultiplier)
	//	{
	//		mRadiusMultiplier = RadiusMultiplier;
	//	}

	//	/** Get skydome radius
	//	    @param c Camera
	//	    @return Skydome radius relative to the given camera
	//	 */
	//	const float getSkydomeRadius(Ogre::Camera* c) const;
private:
	MeshManager* _Mgr;
};
}
