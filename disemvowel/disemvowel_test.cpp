#include <gtest/gtest.h>

#include "disemvowel.h"

TEST(Disemvowel, HandleEmptyString) {
    char *out = disemvowel((char*)"");
    ASSERT_STREQ("", out);
    free(out);
}

TEST(Disemvowel, HandleNoVowels) {
  char *out = disemvowel((char*)"pqrst");
  ASSERT_STREQ("pqrst", out);
  free(out);
}

TEST(Disemvowel, HandleOnlyVowels) {
  char *out = disemvowel((char*)"aeiouAEIOUOIEAuoiea");
  ASSERT_STREQ("", out);
  free(out);
}

TEST(Disemvowel, HandleMorrisMinnesota) {
  char *out = disemvowel((char*)"Morris, Minnesota");
  ASSERT_STREQ("Mrrs, Mnnst", out);
  free(out);
}

TEST(Disemvowel, HandlePunctuation) {
  char *out = disemvowel((char*)"An (Unexplained) Elephant!");
  ASSERT_STREQ("n (nxplnd) lphnt!", out);
  free(out);
}

TEST(Disemvowel, HandleLongString) {
  char *str;
  int size;
  int i;

  size = 50000;
  str = (char*) calloc(size, sizeof(char));
  str[0] = 'x';
  str[1] = 'y';
  str[2] = 'z';
  for (i = 3; i < size-1; ++i) {
    str[i] = 'a';
  }
  str[size-1] = '\0';
  
  char *out = disemvowel(str);
  ASSERT_STREQ("xyz", out);
  free(out);
  free(str);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
