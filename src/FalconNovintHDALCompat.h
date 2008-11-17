/***
 * @file FalconNovintHDALCompat.h
 * @brief Utility class for compatibility with Novint's HDAL SDK classes
 * @author Kyle Machulis (kyle@nonpolynomial.com)
 * @version $Id: FalconNovintHDALCompat.h 204 2008-10-12 01:36:48Z kmachulis $
 * @copyright (c) 2007-2008 Nonpolynomial Labs/Kyle Machulis
 * @license BSD License
 *
 * $HeadURL: https://kmachulis@libnifalcon.svn.sourceforge.net/svnroot/libnifalcon/trunk/libnifalcon_hdal/src/FalconNovintHDALCompat.h $
 * 
 * Project info at http://libnifalcon.sourceforge.net/ 
 *
 */

#ifndef FALCON_NOVINT_HDAL_COMPAT
#define FALCON_NOVINT_HDAL_COMPAT

#include <boost/thread.hpp>
#include "util/FalconDeviceBoostThread.h"

namespace libnifalcon
{
	class FalconNovintHDALCompat : public FalconDeviceBoostThread
	{
		typedef int (*HDLServoOp) (void *pParam);
		struct HDLServoObj
		{
			uint32_t handle;
			HDLServoOp func;
			void* param;
			bool delete_now;
			HDLServoObj(uint32_t h, HDLServoOp f, void* p) : handle(h), func(f), param(p), delete_now(false) {}			
		};
		struct isOpDeleteable
		{
			bool operator() (const HDLServoObj& obj) { return obj.delete_now; }
		};
	public:
		FalconNovintHDALCompat();
		virtual ~FalconNovintHDALCompat();
		int addServoOp(HDLServoOp o, void* param);
 		bool removeServoOp(int op_handle);
		virtual void runThreadLoop();
	protected:
		void runServoOps();
		uint32_t m_opHandleCount;
		uint32_t m_deviceHandleCount;
		std::list<HDLServoObj> m_servoOps;
	};
}

#endif
