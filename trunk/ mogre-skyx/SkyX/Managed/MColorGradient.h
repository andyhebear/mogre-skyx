#pragma once

#include "MColorFrame.h";
#include "ColorGradient.h";

namespace SkyX
{
public ref class MColorGradient
{
public:
	MColorGradient(const ColorGradient nativePointer)
	{
		_cMgr = &nativePointer;
	}

	MColorGradient(void)
	{
		_Mgr = new ColorGradient();
	}

	/** Destructor 
		 */
		~MColorGradient(){
			if (_Mgr != nullptr) {
				delete _Mgr;
			}
			if (_cMgr != nullptr) {
				delete _cMgr;
			}
			
		}

		/** Add color frame
		    @param CFrame Color frame
		 */
		inline void AddColorFrame(MColorFrame^ colorFrame)
		{
			if (_Mgr != nullptr) {
			_Mgr->addCFrame(*(ColorGradient::ColorFrame*)colorFrame->NativePointer());
			}
		}

		/** Clear color gradient
		 */
		inline void clear()
		{
			if (_Mgr != nullptr) {
				_Mgr->clear();
			}
		}

		/** Get color value
		    @param p The gradient point in [0,1] range
			@return Color at the given gradient position
		 */
		inline Mogre::Vector3^ GetColor(float position) {
			if (_Mgr != nullptr) {
				return *((Mogre::Vector3*)&_Mgr->getColor(position));
			}
			if (_cMgr != nullptr) {
				return *((Mogre::Vector3*)&_cMgr->getColor(position));
			}
		}

		inline void* NativePointer() {
			return (void*)_Mgr;
		}
private:
	ColorGradient* _Mgr;
	const ColorGradient* _cMgr;
};

}