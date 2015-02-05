#include "Cello.h"
#include "ptest.h"

PT_FUNC(test_bool_ord) {
  PT_ASSERT(eq(True, True));
  PT_ASSERT(eq(False, False));
  PT_ASSERT(gt(True, False));
  PT_ASSERT(lt(False, True)); 
}

PT_FUNC(test_bool_hash) {
  PT_ASSERT(hash(True) is 1);
  PT_ASSERT(hash(False) is 0);
}

PT_FUNC(test_bool_ctypes) {
  PT_ASSERT(c_int(True) is 1);
  PT_ASSERT(c_int(False) is 0);
  PT_ASSERT(c_float(True) is 1.0);
  PT_ASSERT(c_float(False) is 0.0);
  PT_ASSERT_STR_EQ(c_str(False), "False");
  PT_ASSERT_STR_EQ(c_str(True), "True");
}

PT_FUNC(test_char_new) {
  
  var char0 = $(Char, 'a');
  var char1 = new(Char, $(Char, 'b'));
  var char2 = copy(char0);
  
  PT_ASSERT(char0);
  PT_ASSERT(char1);
  
  PT_ASSERT(c_char(char0) is 'a');
  PT_ASSERT(c_char(char1) is 'b');
  PT_ASSERT(c_char(char2) is 'a');
  
  assign(char1, char2);
  
  PT_ASSERT(char1 isnt char2);
  PT_ASSERT(c_char(char1) is 'a');
  
  del(char1);
  del(char2);
  
}

PT_FUNC(test_char_ord) {
  PT_ASSERT( gt($(Char, 'b'), $(Char, 'a')) );
  PT_ASSERT( gt($(Char, 'z'), $(Char, 'g')) );
  PT_ASSERT( gt($(Char, 'a'), $(Char, 'A')) );
  PT_ASSERT( gt($(Char, 'G'), $(Char, 'F')) );
  PT_ASSERT( lt($(Char, 'V'), $(Char, 't')) );
  PT_ASSERT( lt($(Char, 'C'), $(Char, 'x')) );
  PT_ASSERT( lt($(Char, 'Y'), $(Char, 'Z')) );
  PT_ASSERT( eq($(Char, 'h'), $(Char, 'h')) );
  PT_ASSERT( ge($(Char, 'T'), $(Char, 'T')) );
  PT_ASSERT( le($(Char, 'A'), $(Char, 'a')) );
  PT_ASSERT( le($(Char, 'a'), $(Char, 'a')) );
  PT_ASSERT( neq($(Char, 'T'), $(Char, 'V')) );
}

PT_FUNC(test_char_hash) {
  PT_ASSERT( hash($(Char, 'A')) is 65);
  PT_ASSERT( hash($(Char, 'b')) is 98);
  PT_ASSERT( hash($(Char, 'z')) is 122);
}

PT_FUNC(test_int_new) {
  
  var int0 = $(Int, 1);
  var int1 = new(Int, $(Int, 24313));
  var int2 = copy(int0);
  
  PT_ASSERT(int0);
  PT_ASSERT(int1);
  PT_ASSERT(int2);
  
  PT_ASSERT(c_int(int0) is 1);
  PT_ASSERT(c_int(int1) is 24313);
  PT_ASSERT(c_int(int2) is 1);
  
  assign(int2, int1);
  
  PT_ASSERT( not(int2 is int1) );
  PT_ASSERT(c_int(int2) is 24313);
  
  del(int1);
  del(int2);
  
}

PT_FUNC(test_int_ord) {
  
  PT_ASSERT( gt($(Int, 5),    $(Int, 0)) );
  PT_ASSERT( gt($(Int, 5133), $(Int, 232)) );
  PT_ASSERT( lt($(Int, 2332), $(Int, 9992)) );
  PT_ASSERT( lt($(Int, 34),   $(Int, 323)) );
  PT_ASSERT( eq($(Int, 111),  $(Int, 111)) );
  PT_ASSERT( eq($(Int, 23),   $(Int, 23)) );
  PT_ASSERT( ge($(Int, 289),  $(Int, 289)) );
  PT_ASSERT( ge($(Int, 8734), $(Int, 289)) );
  PT_ASSERT( le($(Int, 166),  $(Int, 166)) );
  PT_ASSERT( le($(Int, 11),   $(Int, 888)) );
  PT_ASSERT( neq($(Int, 324), $(Int, 685)) );
  PT_ASSERT( neq($(Int, 34),  $(Int, 54)) );
  
}

PT_FUNC(test_int_hash) {
  
  PT_ASSERT( hash($(Int, 34)) is 34 );
  PT_ASSERT( hash($(Int, 11)) is 11 );
  PT_ASSERT( hash($(Int, 06)) is 06 );
  PT_ASSERT( hash($(Int, 8213)) is 8213 );
  
}

PT_FUNC(test_int_num) {
  
  var tester = $(Int, 0);
  
  PT_ASSERT(c_int(tester) is 0);
  
  madd(tester, $(Int, 10)); PT_ASSERT(c_int(tester) is 10);
  msub(tester, $(Int, 4)); PT_ASSERT(c_int(tester) is 6);
  mmul(tester, $(Int, 10)); PT_ASSERT(c_int(tester) is 60);
  mdiv(tester, $(Int, 3)); PT_ASSERT(c_int(tester) is 20);
  mneg(tester); PT_ASSERT(c_int(tester) is -20);
  mabs(tester); PT_ASSERT(c_int(tester) is 20);
  mabs(tester); PT_ASSERT(c_int(tester) is 20);
  
}

PT_FUNC(test_int_look) {
  /* TODO */
}

PT_FUNC(test_int_show) {
  /* TODO */
}

PT_FUNC(test_float_new) {
  
  var float0 = $(Float, 1.0);
  var float1 = new(Float, $(Float, 24.313));
  var float2 = copy(float0);
  
  PT_ASSERT(float0);
  PT_ASSERT(float1);
  PT_ASSERT(float2);
  
  PT_ASSERT(c_float(float0) is 1.0);
  PT_ASSERT(c_float(float1) is 24.313);
  PT_ASSERT(c_float(float2) is 1.0);
  
  assign(float2, float1);
  
  PT_ASSERT( not(float2 is float1) );
  PT_ASSERT(c_float(float2) is 24.313);
  
  del(float1);
  del(float2);
  
}

PT_FUNC(test_float_ord) {
  
  PT_ASSERT( gt($(Float, 5.0),    $(Float, 0.0)) );
  PT_ASSERT( gt($(Float, 51.33), $(Float, 2.32)) );
  PT_ASSERT( lt($(Float, 23.32), $(Float, 99.92)) );
  PT_ASSERT( lt($(Float, 31.0),   $(Float, 32.3)) );
  PT_ASSERT( eq($(Float, 1.11),  $(Float, 1.11)) );
  PT_ASSERT( eq($(Float, 23.55),   $(Float, 23.55)) );
  PT_ASSERT( ge($(Float, 2.89),  $(Float, 2.89)) );
  PT_ASSERT( ge($(Float, 87.34), $(Float, 2.89)) );
  PT_ASSERT( le($(Float, 16.6),  $(Float, 16.6)) );
  PT_ASSERT( le($(Float, 1.1),   $(Float, 88.8)) );
  PT_ASSERT( neq($(Float, 3.24), $(Float, 6.85)) );
  PT_ASSERT( neq($(Float, 3.4),  $(Float, 5.4)) );
  
}

union type_interp {
  double c_float;
  int64_t c_int;
};

PT_FUNC(test_float_hash) {
  
  union type_interp r0 = { 34.0 };
  union type_interp r1 = { 11.0 };
  union type_interp r2 = { 0.6 };
  union type_interp r3 = { 82.13 };
  
  PT_ASSERT( hash($(Float, 34.0)) is r0.c_int );
  PT_ASSERT( hash($(Float, 11.0)) is r1.c_int );
  PT_ASSERT( hash($(Float, 0.6)) is r2.c_int );
  PT_ASSERT( hash($(Float, 82.13)) is r3.c_int );
  
}

PT_FUNC(test_float_num) {
  
  double base = 0.0;
  var mirror = $(Float, 0.0);
  
  base += 0.1; madd(mirror, $(Float, 0.1));
  PT_ASSERT(c_float(mirror) is base);
  
  base *= 4.0; mmul(mirror, $(Float, 4.0));
  PT_ASSERT(c_float(mirror) is base);
  
  base /= 2.0; mdiv(mirror, $(Float, 2.0));
  PT_ASSERT(c_float(mirror) is base);
  
  base = -base; mneg(mirror);
  PT_ASSERT(c_float(mirror) is base);  
  
  base = fabs(base); mabs(mirror);
  PT_ASSERT(c_float(mirror) is base);  
  
}

PT_FUNC(test_float_look) {
  /* TODO */
}

PT_FUNC(test_float_show) {
  /* TODO */
}

PT_FUNC(test_string_new) {
  
  var s0 = $(String, "Hello");
  var s1 = new(String, $(String, "There"));
  var s2 = copy(s0);
  
  PT_ASSERT(s0);
  PT_ASSERT(s1);
  PT_ASSERT(s2);
  
  PT_ASSERT_STR_EQ(c_str(s0), "Hello");
  PT_ASSERT_STR_EQ(c_str(s1), "There");
  PT_ASSERT_STR_EQ(c_str(s2), "Hello");
  
  assign(s2, s1);
  
  PT_ASSERT( not(s1 is s2) );
  PT_ASSERT_STR_EQ( c_str(s2), "There" );
  
  del(s1);
  del(s2);
  
}

PT_FUNC(test_string_ord) {
  
  PT_ASSERT( gt($S("Ball"),    $S("Apple")) );
  PT_ASSERT( gt($S("dog"),     $S("cat")) );
  PT_ASSERT( lt($S("great"),   $S("hello")) );
  PT_ASSERT( lt($S("Yellow"),  $S("Zoo")) );
  PT_ASSERT( eq($S("Hello"),   $S("Hello")) );
  PT_ASSERT( eq($S("there"),   $S("there")) );
  PT_ASSERT( ge($S("Hello"),   $S("Hello")) );
  PT_ASSERT( ge($S("tooting"), $S("red")) );
  PT_ASSERT( le($S("guard"),   $S("guardian")) );
  PT_ASSERT( le($S("keep"),    $S("keep")) );
  PT_ASSERT(neq($S("Hello"),   $S("hello")) );
  PT_ASSERT(neq($S("group"),   $S("GROUP")) );
  
}

PT_FUNC(test_string_len) {
  /* TODO */
}

PT_FUNC(test_string_get) {
  
  var s0 = new(String, $(String, "Balloons"));
  
  PT_ASSERT(len(s0) is 8);
  PT_ASSERT(mem(s0, $(String, "Ball")));
  PT_ASSERT(mem(s0, $(String, "oon")));
  PT_ASSERT(mem(s0, $(String, "Balloons")));
  PT_ASSERT(mem(s0, $(Char, 'l')));
  
  rem(s0, $(String, "oons"));
  
  PT_ASSERT_STR_EQ(c_str(s0), "Ball");
  
  clear(s0);
  
  PT_ASSERT(len(s0) is 0);
  PT_ASSERT_STR_EQ(c_str(s0), "");
  
  
  del(s0);
  
}

PT_FUNC(test_string_hash) {
  
  uint64_t v0 = 4771441285123272284ULL;
  uint64_t v1 = 17415363727859751682ULL;
  uint64_t v2 = 11867268813077774525ULL;
  
  PT_ASSERT(hash($S("Hello")) is v0);
  PT_ASSERT(hash($S("There")) is v1);
  PT_ASSERT(hash($S("People")) is v2);
  
}

PT_FUNC(test_string_reverse) {
  
  var s0 = new(String, $(String, "Hello"));
  var s1 = new(String, $(String, "olleH"));
  
  PT_ASSERT( neq(s0, s1) );
  
  reverse(s0);
  
  PT_ASSERT( eq(s0, s1) );
  
  del(s0);
  del(s1);
  
}

PT_FUNC(test_string_clear) {
  /* TODO */
}

PT_FUNC(test_string_look) {
  /* TODO */
}

PT_FUNC(test_string_show) {
  /* TODO */
}

PT_FUNC(test_array_new) {
  
  var a0 = new(Array, Int, $(Int, 1), $(Int, 5), $(Int, 10));
  var a1 = new(Array, Float, $(Float, 1.1), $(Float, 2.2));
  var a2 = copy(a0);
  
  PT_ASSERT(a0);
  PT_ASSERT(a1);
  PT_ASSERT(a2);
  
  PT_ASSERT(a0 isnt a1);
  PT_ASSERT(a0 isnt a2);
  PT_ASSERT(a1 isnt a2);
  
  PT_ASSERT( eq(get(a0, $(Int, 0)), $(Int, 1)) );
  PT_ASSERT( eq(get(a1, $(Int, 0)), $(Float, 1.1)) );
  PT_ASSERT( eq(get(a2, $(Int, 0)), $(Int, 1)) );
  
  assign(a2, a1);
  
  PT_ASSERT(a2 isnt a1);
  PT_ASSERT( eq(get(a2, $(Int, 0)), $(Float, 1.1)) );
  
  del(a0);
  del(a1);
  del(a2);
  
}

PT_FUNC(test_array_eq) {
  
  var a0 = new(Array, Int, $(Int, 1), $(Int, 5), $(Int, 10));
  var a1 = new(Array, Int, $(Int, 1), $(Int, 5), $(Int, 10));
  var a2 = new(Array, Int, $(Int, 2), $(Int, 5), $(Int, 10));
  
  PT_ASSERT(a0 isnt a1);
  PT_ASSERT(a0 isnt a2);
  
  PT_ASSERT( eq(a0, a1) );
  PT_ASSERT( neq(a0, a2) );
  
  del(a0);
  del(a1);
  del(a2);
  
}

PT_FUNC(test_array_len) {
  /* TODO */
}

PT_FUNC(test_array_get) {
  
  var a0 = new(Array, Int, $(Int, 1), $(Int, 5), $(Int, 10));
  
  PT_ASSERT(len(a0) is 3);
  PT_ASSERT(mem(a0, $(Int, 1)));
  PT_ASSERT(mem(a0, $(Int, 5)));
  
  rem(a0, $(Int, 5));
  
  PT_ASSERT(len(a0) is 2);
  PT_ASSERT(mem(a0, $(Int, 1)));
  PT_ASSERT(not mem(a0, $(Int, 5)));
  
  clear(a0);
  
  PT_ASSERT(len(a0) is 0);
  PT_ASSERT(not mem(a0, $(Int, 1)));
  
  del(a0);

  var a1 = new(Array, String, 
    $(String, "Hello"), $(String, "There"), $(String, "People"));
  
  PT_ASSERT( eq(get(a1, $(Int, 0)), $(String, "Hello")) );
  PT_ASSERT( eq(get(a1, $(Int, 1)), $(String, "There")) );
  PT_ASSERT( eq(get(a1, $(Int, 2)), $(String, "People")) );
  
  set(a1, $(Int, 1), $(String, "Blah"));
  
  PT_ASSERT( eq(get(a1, $(Int, 0)), $(String, "Hello")) );
  PT_ASSERT( eq(get(a1, $(Int, 1)), $(String, "Blah")) );
  PT_ASSERT( eq(get(a1, $(Int, 2)), $(String, "People")) );
  
  set(a1, $(Int, 0), $(String, "Foo"));
  set(a1, $(Int, 2), $(String, "Bar"));
  
  PT_ASSERT( eq(get(a1, $(Int, 0)), $(String, "Foo")) );
  PT_ASSERT( eq(get(a1, $(Int, 1)), $(String, "Blah")) );
  PT_ASSERT( eq(get(a1, $(Int, 2)), $(String, "Bar")) );
  
  del(a1);
  
}

PT_FUNC(test_array_push) {
  
  var a0 = new(Array, Int);
  
  PT_ASSERT(len(a0) is 0);
  
  push(a0, $(Int, 1));
  
  PT_ASSERT(len(a0) is 1);
  PT_ASSERT( eq(get(a0, $(Int, 0)), $(Int, 1)) );
  
  push(a0, $(Int, 3));
  
  PT_ASSERT(len(a0) is 2);
  PT_ASSERT( eq(get(a0, $(Int, 0)), $(Int, 1)) );
  PT_ASSERT( eq(get(a0, $(Int, 1)), $(Int, 3)) );
  
  push_at(a0, $(Int, 10), $(Int, 0));
  
  PT_ASSERT(len(a0) is 3);
  PT_ASSERT( eq(get(a0, $(Int, 0)), $(Int, 10)) );
  PT_ASSERT( eq(get(a0, $(Int, 1)), $(Int, 1)) );
  PT_ASSERT( eq(get(a0, $(Int, 2)), $(Int, 3)) );
  
  push_at(a0, $(Int, 20), $(Int, 1));
  
  PT_ASSERT(len(a0) is 4);
  PT_ASSERT( eq(get(a0, $(Int, 0)), $(Int, 10)) );
  PT_ASSERT( eq(get(a0, $(Int, 1)), $(Int, 20)) );
  PT_ASSERT( eq(get(a0, $(Int, 2)), $(Int, 1)) );
  PT_ASSERT( eq(get(a0, $(Int, 3)), $(Int, 3)) );
  
  pop_at(a0, $(Int, 2));
  
  PT_ASSERT(len(a0) is 3);
  PT_ASSERT( eq(get(a0, $(Int, 0)), $(Int, 10)) );
  PT_ASSERT( eq(get(a0, $(Int, 1)), $(Int, 20)) );
  PT_ASSERT( eq(get(a0, $(Int, 2)), $(Int, 3)) );
  
  pop_at(a0, $(Int, 0));
  
  PT_ASSERT(len(a0) is 2);
  PT_ASSERT( eq(get(a0, $(Int, 0)), $(Int, 20)) );
  PT_ASSERT( eq(get(a0, $(Int, 1)), $(Int, 3)) );
  
  pop(a0);
  
  PT_ASSERT(len(a0) is 1);
  PT_ASSERT( eq(get(a0, $(Int, 0)), $(Int, 20)) );
  
  pop(a0);
  
  PT_ASSERT(len(a0) is 0);
  
  del(a0);
  
}

PT_FUNC(test_array_concat) {
  /* TODO */
}

PT_FUNC(test_array_clear) {
  /* TODO */
}

PT_FUNC(test_array_sort) {
  /* TODO */
}

PT_FUNC(test_array_reserve) {
  /* TODO */
}

PT_FUNC(test_array_iter) {
  
  var a0 = new(Array, String, 
    $(String, "Hello"), $(String, "There"), $(String, "People"));
  
  int counter = 0;
  
  foreach(item in a0) {
    
    switch(counter) {
      case 0: PT_ASSERT( eq(item, $(String, "Hello")) ); break;
      case 1: PT_ASSERT( eq(item, $(String, "There")) ); break;
      case 2: PT_ASSERT( eq(item, $(String, "People")) ); break;
    }
    
    counter++;
  }
  
  PT_ASSERT(counter is 3);
  
  counter = 0;
  
  foreach(item0 in a0) {
    foreach(item1 in a0) {
      counter++;
    }
  }
  
  PT_ASSERT(counter is 9);
  del(a0);
  
}

PT_FUNC(test_array_reverse) {
  
  var a0 = new(Array, String, 
    $(String, "Hello"), $(String, "There"), $(String, "People"));
  
  var a1 = new(Array, String, 
    $(String, "People"), $(String, "There"), $(String, "Hello"));
  
  PT_ASSERT( not eq(a0, a1) );
  
  reverse(a0);
  
  PT_ASSERT( eq(a0, a1) );
  
  del(a0);
  del(a1);

}

PT_FUNC(test_list_new) {
  
  var a0 = new(List, Int, $(Int, 1), $(Int, 5), $(Int, 10));
  var a1 = new(List, Float, $(Float, 1.1), $(Float, 2.2));
  var a2 = copy(a0);
  
  
  PT_ASSERT(a0);
  PT_ASSERT(a1);
  PT_ASSERT(a2);
  
  PT_ASSERT(a0 isnt a1);
  PT_ASSERT(a0 isnt a2);
  PT_ASSERT(a1 isnt a2);
  
  PT_ASSERT( eq(get(a0, $(Int, 0)), $(Int, 1)) );
  PT_ASSERT( eq(get(a1, $(Int, 0)), $(Float, 1.1)) );
  PT_ASSERT( eq(get(a2, $(Int, 0)), $(Int, 1)) );
  
  assign(a2, a1);
  
  PT_ASSERT(a2 isnt a1);
  PT_ASSERT( eq(get(a2, $(Int, 0)), $(Float, 1.1)) );
  
  del(a0);
  
  del(a1);
  del(a2);
  
}

PT_FUNC(test_list_eq) {
  
  var a0 = new(List, Int, $(Int, 1), $(Int, 5), $(Int, 10));
  var a1 = new(List, Int, $(Int, 1), $(Int, 5), $(Int, 10));
  var a2 = new(List, Int, $(Int, 2), $(Int, 5), $(Int, 10));
  
  PT_ASSERT(a0 isnt a1);
  PT_ASSERT(a0 isnt a2);
  
  PT_ASSERT( eq(a0, a1) );
  PT_ASSERT( neq(a0, a2) );
  
  del(a0);
  del(a1);
  del(a2);
  
}

PT_FUNC(test_list_len) {
  /* TODO */
}

PT_FUNC(test_list_get) {
  
  var a0 = new(List, Int, $(Int, 1), $(Int, 5), $(Int, 10));
  
  PT_ASSERT(len(a0) is 3);
  PT_ASSERT(mem(a0, $(Int, 1)));
  PT_ASSERT(mem(a0, $(Int, 5)));
  
  rem(a0, $(Int, 5));
  
  PT_ASSERT(len(a0) is 2);
  PT_ASSERT(mem(a0, $(Int, 1)));
  PT_ASSERT(not mem(a0, $(Int, 5)));
  
  clear(a0);
  
  PT_ASSERT(len(a0) is 0);
  PT_ASSERT(not mem(a0, $(Int, 1)));
  
  del(a0);

  var a1 = new(List, String, 
    $(String, "Hello"), $(String, "There"), $(String, "People"));
  
  PT_ASSERT( eq(get(a1, $(Int, 0)), $(String, "Hello")) );
  PT_ASSERT( eq(get(a1, $(Int, 1)), $(String, "There")) );
  PT_ASSERT( eq(get(a1, $(Int, 2)), $(String, "People")) );
  
  set(a1, $(Int, 1), $(String, "Blah"));
  
  PT_ASSERT( eq(get(a1, $(Int, 0)), $(String, "Hello")) );
  PT_ASSERT( eq(get(a1, $(Int, 1)), $(String, "Blah")) );
  PT_ASSERT( eq(get(a1, $(Int, 2)), $(String, "People")) );
  
  set(a1, $(Int, 0), $(String, "Foo"));
  set(a1, $(Int, 2), $(String, "Bar"));
  
  PT_ASSERT( eq(get(a1, $(Int, 0)), $(String, "Foo")) );
  PT_ASSERT( eq(get(a1, $(Int, 1)), $(String, "Blah")) );
  PT_ASSERT( eq(get(a1, $(Int, 2)), $(String, "Bar")) );
  
  del(a1);
  
}

PT_FUNC(test_list_push) {
  
  var a0 = new(List, Int);
  
  PT_ASSERT(len(a0) is 0);
  
  push(a0, $(Int, 1));
  
  PT_ASSERT(len(a0) is 1);
  PT_ASSERT( eq(get(a0, $(Int, 0)), $(Int, 1)) );
  
  push(a0, $(Int, 3));
  
  PT_ASSERT(len(a0) is 2);
  PT_ASSERT( eq(get(a0, $(Int, 0)), $(Int, 1)) );
  PT_ASSERT( eq(get(a0, $(Int, 1)), $(Int, 3)) );
  
  show(a0);

  push_at(a0, $(Int, 10), $(Int, 0));
  
  show(a0);
  
  PT_ASSERT(len(a0) is 3);
  PT_ASSERT( eq(get(a0, $(Int, 0)), $(Int, 10)) );
  PT_ASSERT( eq(get(a0, $(Int, 1)), $(Int, 1)) );
  PT_ASSERT( eq(get(a0, $(Int, 2)), $(Int, 3)) );
  
  /*
  
  push_at(a0, $(Int, 20), $(Int, 1));
  
  PT_ASSERT(len(a0) is 4);
  PT_ASSERT( eq(get(a0, $(Int, 0)), $(Int, 10)) );
  PT_ASSERT( eq(get(a0, $(Int, 1)), $(Int, 20)) );
  PT_ASSERT( eq(get(a0, $(Int, 2)), $(Int, 1)) );
  PT_ASSERT( eq(get(a0, $(Int, 3)), $(Int, 3)) );
  
  pop_at(a0, $(Int, 2));
  
  PT_ASSERT(len(a0) is 3);
  PT_ASSERT( eq(get(a0, $(Int, 0)), $(Int, 10)) );
  PT_ASSERT( eq(get(a0, $(Int, 1)), $(Int, 20)) );
  PT_ASSERT( eq(get(a0, $(Int, 2)), $(Int, 3)) );
  
  pop_at(a0, $(Int, 0));
  
  PT_ASSERT(len(a0) is 2);
  PT_ASSERT( eq(get(a0, $(Int, 0)), $(Int, 20)) );
  PT_ASSERT( eq(get(a0, $(Int, 1)), $(Int, 3)) );
  
  pop(a0);
  
  PT_ASSERT(len(a0) is 1);
  PT_ASSERT( eq(get(a0, $(Int, 0)), $(Int, 20)) );
  
  pop(a0);
  
  PT_ASSERT(len(a0) is 0);
  */
  
  del(a0);
  
}

PT_FUNC(test_list_concat) {
  /* TODO */
}

PT_FUNC(test_list_clear) {
  /* TODO */
}

PT_FUNC(test_list_sort) {
  /* TODO */
}

PT_FUNC(test_list_reserve) {
  /* TODO */
}

PT_FUNC(test_list_iter) {
  
  var a0 = new(List, String, $S("Hello"), $S("There"), $S("People"));
  
  int counter = 0;
  
  foreach(item in a0) {
    
    switch(counter) {
      case 0: PT_ASSERT( eq(item, $(String, "Hello")) ); break;
      case 1: PT_ASSERT( eq(item, $(String, "There")) ); break;
      case 2: PT_ASSERT( eq(item, $(String, "People")) ); break;
    }
    
    counter++;
  }
  
  PT_ASSERT(counter is 3);
  
  counter = 0;
  
  foreach(item0 in a0) {
    foreach(item1 in a0) {
      counter++;
    }
  }
  
  PT_ASSERT(counter is 9);
  del(a0);
  
}

PT_FUNC(test_list_reverse) {
  
  var a0 = new(List, String, $S("Hello"), $S("There"), $S("People"));
  var a1 = new(List, String, $S("People"), $S("There"), $S("Hello"));
  
  PT_ASSERT( not eq(a0, a1) );
  
  reverse(a0);
  
  PT_ASSERT( eq(a0, a1) );
  
  del(a0);
  del(a1);

}

PT_FUNC(test_table_new) {
  
  var t0 = new(Table, String, Int);
  set(t0, $(String, "Hello"), $(Int, 2));
  set(t0, $(String, "There"), $(Int, 5));
  
  var t1 = new(Table, String, Int);
  set(t1, $(String, "Bonjour"), $(Int, 9));
  set(t1, $(String, "Where"), $(Int, 5));
  
  var t2 = copy(t0);
  
  PT_ASSERT(t0);
  PT_ASSERT(t1);
  PT_ASSERT(t2);
  
  PT_ASSERT(t0 isnt t2);
  PT_ASSERT(t0 isnt t1);
  
  PT_ASSERT(mem(t0, $(String, "Hello")));
  PT_ASSERT(mem(t1, $(String, "Bonjour")));
  PT_ASSERT(mem(t2, $(String, "There")));
  
  assign(t2, t1);
  
  PT_ASSERT(mem(t2, $(String, "Where")));
  PT_ASSERT(mem(t2, $(String, "Bonjour")));
  PT_ASSERT(not mem(t2, $(String, "Hello")));
  PT_ASSERT(not mem(t2, $(String, "There")));
  
  del(t0);
  del(t1);
  del(t2);
  
}

PT_FUNC(test_table_len) {
  /* TODO */
}

PT_FUNC(test_table_get) {
  
  var t0 = new(Table, String, Int);
  set(t0, $(String, "Hello"), $(Int, 2));
  set(t0, $(String, "There"), $(Int, 5));
  
  PT_ASSERT(len(t0) is 2);
  PT_ASSERT(mem(t0, $(String, "Hello")));
  
  rem(t0, $(String, "Hello"));
  
  PT_ASSERT(len(t0) is 1);
  PT_ASSERT(not mem(t0, $(String, "Hello")));
  PT_ASSERT(mem(t0, $(String, "There")));
  
  clear(t0);
  
  PT_ASSERT(len(t0) is 0);
  PT_ASSERT(not mem(t0, $(String, "Hello")));
  PT_ASSERT(not mem(t0, $(String, "There")));
  
  del(t0);


  var t1 = new(Table, String, Int);
  set(t1, $(String, "Hello"), $(Int, 2));
  set(t1, $(String, "There"), $(Int, 5));
  
  var i0 = get(t1, $(String, "Hello"));
  var i1 = get(t1, $(String, "There"));
  
  PT_ASSERT( eq(i0, $(Int, 2)) );
  PT_ASSERT( eq(i1, $(Int, 5)) );
  
  set(t1, $(String, "Hello"), $(Int, 6));
  
  var i2 = get(t1, $(String, "Hello"));
  PT_ASSERT( eq(i2, $(Int, 6)) );
  
  del(t1);
  
}

PT_FUNC(test_table_clear) {
  /* TODO */
}

PT_FUNC(test_table_rehash) {
  
  var d0 = new(Table, Int, Int);
  var value = $(Int, 23);
  var test_key = Undefined;

  int max = 1000;
  int r = rand() % max;

  for (int i = 0; i < max; i++) {
    var key = $(Int, i);
    if (i == r) {
      test_key = key;
    }
    set(d0, key, value);
  }

  PT_ASSERT(test_key isnt Undefined);
  PT_ASSERT(eq(get(d0, test_key), value));
  PT_ASSERT(len(d0) is max);

  del(d0);
}

PT_FUNC(test_table_reserve) {
  /* TODO */
}

PT_FUNC(test_table_iter) {
  
  var t0 = new(Table, String, Int);
  set(t0, $(String, "Hello"), $(Int, 2));
  set(t0, $(String, "There"), $(Int, 5));
  
  foreach(key in t0) {
    
    var val = get(t0, key);
    
    PT_ASSERT(
       (eq(key, $S("Hello")) and eq(val, $I(2)))
    or (eq(key, $S("There")) and eq(val, $I(5))));
    
  }
  
  del(t0);

}

PT_FUNC(test_file_new) {
  
  var f0 = new(File, $S("test.bin"), $S("w")); 
  var f1 = $(File, None);
  
  PT_ASSERT(f0);
  PT_ASSERT(f1);
  
  PT_ASSERT(f0 isnt f1);
  
  del(f0);
  
}

static char testoutput1[] = "This is a test\n";
static char testoutput2[] = "This is a sample\n";
static char testinput[512];

PT_FUNC(test_file_stream) {
  
  var f0 = $(File, NULL);
  
  sopen(f0, $S("test.txt"), $S("w"));
  swrite(f0, testoutput1, $(Int, sizeof(testoutput1)));
  sclose(f0);  
  
  sopen(f0, $S("test.txt"), $S("r"));
  sread(f0, testinput, $(Int, sizeof(testoutput1)));
  sclose(f0);
  
  PT_ASSERT_STR_EQ(testinput, testoutput1);
  
}

PT_FUNC(test_file_begin) {
  /* TODO */
}

PT_SUITE(suite_data) {

  PT_REG(test_bool_ord);
  PT_REG(test_bool_hash);
  PT_REG(test_bool_ctypes);
  
  PT_REG(test_char_new);
  PT_REG(test_char_ord);
  PT_REG(test_char_hash);

  PT_REG(test_int_new);
  PT_REG(test_int_ord);
  PT_REG(test_int_hash);
  PT_REG(test_int_num);
  PT_REG(test_int_look);
  PT_REG(test_int_show);

  PT_REG(test_float_new);
  PT_REG(test_float_ord);
  PT_REG(test_float_hash);
  PT_REG(test_float_num);
  PT_REG(test_float_look);
  PT_REG(test_float_show);

  PT_REG(test_string_new);
  PT_REG(test_string_ord);
  PT_REG(test_string_len);
  PT_REG(test_string_get);
  PT_REG(test_string_hash);
  PT_REG(test_string_clear);
  PT_REG(test_string_reverse);
  PT_REG(test_string_look);
  PT_REG(test_string_show);

  PT_REG(test_array_new);
  PT_REG(test_array_eq);
  PT_REG(test_array_clear);
  PT_REG(test_array_len);
  PT_REG(test_array_get);
  PT_REG(test_array_push);
  PT_REG(test_array_concat);
  PT_REG(test_array_iter);
  PT_REG(test_array_reverse);
  PT_REG(test_array_reserve);
  PT_REG(test_array_sort);
  
  PT_REG(test_list_new);
  PT_REG(test_list_eq);
  PT_REG(test_list_clear);
  PT_REG(test_list_len);
  PT_REG(test_list_get);
  PT_REG(test_list_push);
  PT_REG(test_list_concat);
  PT_REG(test_list_iter);
  PT_REG(test_list_reverse);
  PT_REG(test_list_reserve);
  PT_REG(test_list_sort);
  
  PT_REG(test_table_new);
  PT_REG(test_table_len);
  PT_REG(test_table_get);
  PT_REG(test_table_rehash);
  PT_REG(test_table_iter);
  PT_REG(test_table_reserve);
  
  /*
  PT_REG(test_map_new);
  PT_REG(test_map_len);
  PT_REG(test_map_get);
  PT_REG(test_map_iter);
  */
  
  PT_REG(test_file_new);
  PT_REG(test_file_begin);
  PT_REG(test_file_stream);

  /* TODO: Box, Ref, Range, Slice */

}
