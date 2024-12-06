#include <cstring>

class Light_string {
     private:
          char *str;
     public:
          Light_string() {
               this -> str = new char[1];
               str[0] = '\0';
          }
          explicit Light_string(const char * chain) {
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

          const size_t length() const {
               return strlen(this -> str);
          }

          const char * c_str() {
               return this -> str;
          } 
};
