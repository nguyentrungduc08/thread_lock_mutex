namespace cpp Thread_Lock_Mutex

service Data {
   i32 put(1: i32 user),
   i32 get(1: i32 uid),
   i32 update(1: i32 index, 2: i32 value)
}
