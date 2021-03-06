#include "myQueue.h"

#include <unistd.h>

t_myQueue::t_myQueue()
{
   pipe(fds);
}

t_myQueue::t_myQueue(const t_myQueue &other)
{
   fds[0] = dup(other.fds[0]);
   fds[1] = dup(other.fds[1]);
}

t_myQueue::~t_myQueue()
{
   close(fds[0]);
   close(fds[1]);
}

int t_myQueue::getWaitFd() const
{
   return dup(fds[0]);
}

void t_myQueue::push(const t_message &a_message)
{
   write(fds[1],&a_message,sizeof(a_message));
}

t_message t_myQueue::pop()
{
   t_message the_message;

   if (read(fds[0],&the_message,sizeof(the_message)) == 0)
   {
      the_message.id = t_message::closed;
   }

   return the_message;
}

void t_myQueue::closeRead()
{
   close(fds[0]);
}

void t_myQueue::closeWrite()
{
   close(fds[1]);
}

