#include "tanksMid.h"

t_tanksMid::t_tanksMid(t_sharedData theSharedData) : sharedData(theSharedData)
{
   sharedData.guiQueue.closeRead();
   sharedData.midQueue.closeWrite();
}

t_tanksMid::~t_tanksMid()
{}

void t_tanksMid::run()
{
   t_message mess("Hello world peeps");
   sharedData.guiQueue.push(mess);

   sleep(2);
   t_message mess2("Hello world again peeps");
   sharedData.guiQueue.push(mess2);

   bool status = true;

   while (status)
   {
      t_message aMess = sharedData.midQueue.pop();

      status = processMessage(aMess);
      aMess.close();
   }
}