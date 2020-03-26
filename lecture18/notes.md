# Code Reviews
+ Application is a thread itself
+ Network layer is also a thread
```
trivial demo
demo.start
demo.join
```
+ LocalNetowrkMessageManager connect_local(nod_id)

LocalNetworkMessageManager
- KeyValueStore
- Queue

+ Move stuff to actual header files, and then implement elsewhere
inc: -> headers
src: -> cpp

ReceiveMessageManager 
+ deals with messages in a distributed way

