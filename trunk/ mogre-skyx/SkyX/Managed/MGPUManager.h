#pragma once

#include "GPUManager.h";

namespace SkyX {
ref class MGPUManager
{
public:

	MGPUManager(void* nativePointer)
	{
		_Mgr = (GPUManager*)&nativePointer;
	}

	/** Gpu program enum
		 */
		enum class GpuProgramEnum
		{
			// Vertex program
			GPUP_VERTEX   = 0,
			// Fragment program
			GPUP_FRAGMENT = 1
		};

	//	/** Add ground pass (Use for atmospheric scattering effect on the terrain)
	//	    @param GroundPass Ground pass
	//		@param AtmosphereRaidus Atmosphere radius (typically far carmera clip plane)
	//		@param SBT Scene blend type
	//	 */
	//	void addGroundPass(Ogre::Pass* GroundPass, const Ogre::Real& AtmosphereRadius, const Ogre::SceneBlendType& SBT = Ogre::SBT_ADD);

	//	/** Set gpu program int parameter
	//	    @param GpuP Gpu program type (Vertex/Fragment)
	//		@param Name param name
	//		@param Value value
	//		@param UpdateGroundPasses true to update ground passes
	//	 */
	//	void setGpuProgramParameter(const GpuProgram &GpuP, const Ogre::String &Name, const int &Value, const bool& UpdateGroundPasses = true);

	//	/** Set gpu program Ogre::Real parameter
	//	    @param GpuP Gpu program type (Vertex/Fragment)
	//		@param Name param name
	//		@param Value value
	//		@param UpdateGroundPasses true to update ground passes
	//	 */
	//	void setGpuProgramParameter(const GpuProgram &GpuP, const Ogre::String &Name, const Ogre::Real &Value, const bool& UpdateGroundPasses = true);

	//	/** Set gpu program Ogre::Vector2 parameter
	//	    @param GpuP Gpu program type (Vertex/Fragment)
	//		@param Name param name
	//		@param Value value
	//		@param UpdateGroundPasses true to update ground passes
	//	 */
	//	void setGpuProgramParameter(const GpuProgram &GpuP, const Ogre::String &Name, const Ogre::Vector2 &Value, const bool& UpdateGroundPasses = true); 

	//	/** Set gpu program Ogre::Vector3 parameter
	//	    @param GpuP Gpu program type (Vertex/Fragment)
	//		@param Name param name
	//		@param Value value
	//		@param UpdateGroundPasses true to update ground passes
	//	 */
	//	void setGpuProgramParameter(const GpuProgram &GpuP, const Ogre::String &Name, const Ogre::Vector3 &Value, const bool& UpdateGroundPasses = true); 

	//	/** Get skydome material name
	//	    @return Skydome material name
	//	 */
	//	const Ogre::String getSkydomeMaterialName() const;

	//	/** Get moon material name
	//	    @return Moon material name
	//	 */
	//	inline const Ogre::String getMoonMaterialName() const
	//	{
	//		return "SkyX_Moon";
	//	}
private:
	GPUManager* _Mgr;
};
}
