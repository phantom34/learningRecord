__int64 sub_7FF7FF4615A0()
{
  const char *v0; // rcx
  signed __int64 v1; // rbx
  void *v2; // rdi
  __int64 v3; // rcx
  __int64 v4; // r9
  signed __int64 v5; // rdx
  __int64 v6; // r8
  __int64 v8; // [rsp+20h] [rbp-28h]
  unsigned __int64 v9; // [rsp+28h] [rbp-20h]

  sub_7FF7FF461020((__int64)"Here comes the second (and final) phase. It is a puzzle.\n"
                            "The puzzle input is 202020202020.\n"
                            "You need to find out the answer (a 64-bit integer as well) in order to get the key.\n"
                            "\n"
                            "Surprisingly, I am kind enough to offer you some help.\n"
                            "You may enter any integer from 1 to 5, and I will calculate the answer to that input for you"
                            "!\n"
                            "But for input like 202020202020, you need to do something special :)\n"
                            "\n"
                            "If you've figured out the answer, simply enter -1 and then your answer to get the key!\n"
                            "Have fun decoding! (P.S. enter -2 to exit)\n"
                            "\n");
  if ( (signed int)sub_7FF7FF461080((__int64)"%lld", &v9) <= 0 )
  {
    sub_7FF7FF461020((__int64)"Bad Input!\n");
    exit(0);
  }
  if ( v9 == -1i64 )
  {
    sub_7FF7FF461020((__int64)"Please enter your answer:\n");
    if ( (signed int)sub_7FF7FF461080((__int64)"%lld", &v8) <= 0 )
    {
      sub_7FF7FF461020((__int64)"Bad Input!\n");
      exit(0);
    }
    sub_7FF7FF461020((__int64)"The key is:\n");
    if ( v8 < 0 )
    {
      v0 = "..Nice.Try..\n\n";
LABEL_25:
      sub_7FF7FF461020((__int64)v0);
      return 0i64;
    }
    sub_7FF7FF461020(
      (__int64)"%s\n\n",
      (char *)&unk_7FF7FF465640
    + 13
    * (v8
     - 13370
     * (((unsigned __int64)((unsigned __int128)(v8 * (signed __int128)1412824676999145913i64) >> 64) >> 63)
      + ((signed __int64)((unsigned __int128)(v8 * (signed __int128)1412824676999145913i64) >> 64) >> 10))
