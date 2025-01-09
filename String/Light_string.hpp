#include <cstring>

namespace lsstr {
     // create functions
     size_t len(const char *ptr) {
          size_t count = 0;
          while (*ptr++) count++;
          return count;       
     }
}

class Light_string {
     private:
          char *str;
          bool isSetup;
          size_t (*len_func)(const char *);

          void setup() {
               isSetup = true;
               this -> len_func = lsstr::len;
          }
     public:
          Light_string(): len_func(nullptr), isSetup(false) {
               this -> str = new char[1];
               str[0] = '\0';
          }
          explicit Light_string(const char * chain) {
               setup();
               size_t arg_len = strlen(chain);
               this -> str = new char[arg_len + 1];
               strcpy(this -> str, chain);                  // strcpy cares about null terminator
               // Manual coping: 
               // for (size_t i = 0; i < arg_len; ++i) {
               //      this->str[i] = chain[i];
               // }
               // this->str[arg_len] = '\0';                // Add null terminator manually
          }
          ~Light_string() {
               delete [ ] this -> str;
          };

          size_t length() const {
               if (isSetup) {
                    return this -> len_func(this -> str);
               } else {
                    return 0;
               }
          }

          // const size_t length() const {
          //      return strlen(this -> str);
          // }

          const char * c_str() {
               return this -> str;
          } 
};
