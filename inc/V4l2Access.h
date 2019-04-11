/* ---------------------------------------------------------------------------
** This software is in the public domain, furnished "as is", without technical
** support, and with no warranty, express or implied, as to its usefulness for
** any purpose.
**
** V4l2Access.h
** 
** V4L2 wrapper 
**
** -------------------------------------------------------------------------*/


#ifndef V4L2_ACCESS
#define V4L2_ACCESS

#include "V4l2Device.h"
#include "V4l2Capture.h"

class V4l2Access
{
	public:
		enum IoType
		{
			IOTYPE_READWRITE,
			IOTYPE_MMAP,
		};
		
		V4l2Access(V4l2Device* device) : m_device(device) {}
		virtual ~V4l2Access() { delete m_device; }
		
		int getFd()         { return m_device->getFd();         }
		unsigned int getBufferSize() { return m_device->getBufferSize(); }
		unsigned int getFormat()     { return m_device->getFormat();     }
		unsigned int getWidth()      { return m_device->getWidth();      }
		unsigned int getHeight()     { return m_device->getHeight();     }
		void queryFormat()  { m_device->queryFormat();          }

		int isReady()       { return m_device->isReady();       }
		int start()         { return m_device->start();         }
		int stop()          { return m_device->stop();          }

		int setTriggerMode(LiTriggerMode mode) { return m_device->setTriggerMode(getFd(),mode);}
		int softTrigger(){ return m_device->softTrigger(getFd());}
		int triggerDelayTime(unsigned int delay_time_ms){return m_device->triggerDelayTime(getFd() , delay_time_ms);}
	private:
		V4l2Access(const V4l2Access&);
		V4l2Access & operator=(const V4l2Access&);
	
	protected:
		V4l2Device* m_device;		
};


#endif
