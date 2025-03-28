#ifndef bsc_ALGORITHM
#define bsc_ALGORITHM
#include <Arduino.h>
#include <ctype.h>
template <typename alogrithm_data_type>
class algorithm{
  public:
    algorithm()=default;
    const char newline='\n';
    const char tab='\t';
    const char currentline='\0';
    void cout(alogrithm_data_type input, const char escape_sequence){
      if(escape_sequence==this->newline){ Serial.println(input);}
      else if(escape_sequence==this->tab){  Serial.print(input); Serial.print(this->tab);}
      else{ Serial.print(input);}
    }
    alogrithm_data_type get_line(void){
      if(Serial.available()){
        String input="";
        while(Serial.available()){
          input+=(char)Serial.read();
        }
        return static_cast<alogrithm_data_type>(input);
      }
      return "";
    }
    void swap(alogrithm_data_type &input1, alogrithm_data_type &input2){
      alogrithm_data_type temp=input1;
      input1=input2;
      input2=temp;
    }
};
template<>
class algorithm<char>{
  public:
    algorithm()=default;
    const char newline='\n';
    const char tab='\t';
    const char currentline='\0';
    void cout(char input, const char escape_sequence){
      if(escape_sequence==this->newline){ Serial.println(input);}
      else if(escape_sequence==this->tab){  Serial.print(input); Serial.print(this->tab);}
      else{ Serial.print(input);}
    }
    char get_line(void){
      if(Serial.available()){
        String input="";
        while(Serial.available()){
          input+=(char)Serial.read();
        }
        return input.c_str();
      }
      return "";
    }
    void swap(char &input1, char &input2){
      const char temp=input1;
      input1=input2;
      input2=temp;
    }
    String to_String(const char input){
      return String(input);
    }
    String arr_to_String(const char *array, int size){
      String output;
      for(int i=0; i<size; i++){
        output+=String(array[i]);
      }
      return output;
    }
    char string_to_char(const String input){
      return input.c_str();
    }
    char arr_string_to_char(const char *array, int size){
      String output;
      for(int i=0; i<size; i++){
        output+=String(array[i]);
      }
      return output.c_str();
    }
    bool is_alpha(const char input){
      if(isalpha(input)!=true){ return false;}
      else{  return true;}
    }
    bool is_lower(const char input){
      if(islower(input)!=true){ return false;}
      else{ return true;}
    }
    bool is_upper(const char input){
      if(isupper(input)!=true){ return false;}
      else{ return true;}
    }
    char to_upper(const char input){
      return toupper(input);
    }
    char to_lower(const char input){
      return tolower(input);
    }
};
template <>
class algorithm<String>{
  public:
    algorithm()=default;
    const char newline='\n';
    const char tab='\t';
    const char currentline='\0';
    void cout(String input, const char escape_sequence){
      if(escape_sequence==this->newline){ Serial.println(input);}
      else if(escape_sequence==this->tab){  Serial.print(input); Serial.print(this->tab);}
      else{ Serial.print(input);}
    }
    void swap(String &input1, String &input2){
      const String temp=input1;
      input1=input2;
      input2=temp;
    }
    String get_line(void){
      if(Serial.available()){
        String input="";
        while(Serial.available()){
          input+=(char)Serial.read();
        }
        return String(input);
      }
      return "";
    }
    String to_String(String input){
      String result=String(input);
      return result; 
    }
    String arr_to_String(String *array, int size){
      String output;
      for(int i=0; i<size; i++){
      output+=to_String(array[i]);
      }
      return output;
    }
};
template <>
class algorithm<int>{
  public:
    algorithm()=default;
    const char newline='\n';
    const char tab='\t';
    const char currentline='\0';
    void cout(int input, const char escape_sequence){
      if(escape_sequence==this->newline){ Serial.println(input);}
      else if(escape_sequence==this->tab){  Serial.print(input); Serial.print(this->tab);}
      else{ Serial.print(input);}
    }
    void swap(int &input1, int &input2){
      const int temp=input1;
      input1=input2;
      input2=temp;
    }
    int get_line(void){
      if(Serial.available()){
        String input="";
        while(Serial.available()){
          input+=(int)Serial.read();
        }
        return input.toInt();
      }
    }
    String to_String(int input){
      return String(input);
    }
    String arr_to_String(int *array, int size){
      String output;
      for(int i=0; i<size; i++){
        output+=to_String(array[i]);
      }
      return output; 
    }
    int string_to_int(String input){
      return input.toInt();
    }
    bool is_digit(const char input){
      if(isdigit(input)!=true){  return false;}
      else{ return true;}
    }
};
template <>
class algorithm<float>{
  public:
    algorithm()=default;
    const char newline='\n';
    const char tab='\t';
    const char currentline='\0';
    float set_precision(int n_suffix, float input){
      char buffer[20];
      dtostrf(input, 10, n_suffix, buffer);
      String formatted = String(buffer);
      float result = formatted.toFloat();
      return result;
    }
    void cout(float input,int n_suffix, const char escape_sequence){
      if(escape_sequence==this->newline){ Serial.println(set_precision(n_suffix, input), n_suffix);}
      else if(escape_sequence==this->tab){  Serial.print(set_precision(n_suffix, input), n_suffix); Serial.print(this->tab);}
      else{ Serial.print(set_precision(n_suffix, input), n_suffix);}
    }
    void swap(float &input1, float &input2){
      const float temp=input1;
      input1=input2;
      input2=temp;
    }
    float get_line(void){
      if(Serial.available()){
        String input="";
        while(Serial.available()){
          input+=(int)Serial.read();
        }
        return input.toFloat();
      }
    }
    String to_String(float input){
      return String(input);
    }
    String arr_to_String(float *array, int size){
      String output;
      for(int i=0; i<size; i++){
        output+=to_String(array[i]);
      }
      return output;
    }
    float string_to_float(String input){
      return input.toFloat();
    }
};
template <int vector_size, typename vector_type>
class Vector{
  public: 
    static constexpr vector_type invalid=-1;
    vector_type array[vector_size];
    Vector(){
      for(int i=0; i<vector_size; i++){
        array[i]=invalid;
      }
    }
    void sort_invalid(void){
      for(int i=0; i<vector_size; i++){
        for(int j=i+1; j<vector_size; j++){
          if(array[i]!=invalid && array[j]==invalid){
            continue;
          }
          else if(array[i]==invalid && array[j]!=invalid){
            array[i]=array[j];
            array[j]=invalid;
          }
          else if(array[i]==invalid && array[j]==invalid){
            continue;
          }
          else{
            continue;
          }
        }
      }
    }
    void full_sort(void){
      for(int i=0; i<vector_size; i++){
        for(int j=i+1; j<vector_size; j++){
          if(array[i]!=invalid && array[j]==invalid){
            continue;
          }
          else if(array[i]==invalid && array[j]!=invalid){
            array[i]=array[j];
            array[j]=invalid;
          }
          else if(array[i]==invalid && array[j]==invalid){
            continue;
          }
          else{
            continue;
          }
        }
      }
      for(int i=0; i<vector_size; i++){
        for(int j=i+1; j<vector_size; j++){
          if(array[i]!=array[j]){
            continue;
          }
          else{
            array[j]=invalid;
          }
        }
      }
      for(int i=0; i<vector_size; i++){
        for(int j=i+1; j<vector_size; j++){
          if(array[i]!=invalid && array[j]==invalid){
            continue;
          }
          else if(array[i]==invalid && array[j]!=invalid){
            array[i]=array[j];
            array[j]=invalid;
          }
          else if(array[i]==invalid && array[j]==invalid){
            continue;
          }
          else{
            continue;
          }
        }
      }
    }
    vector_type front(void){
      return array[0];
    }
    vector_type back(void){
      return array[vector_size-1];
    }
    vector_type at(int index){
      if(array[index]!=invalid){  return array[index];}
      else{ return invalid;}
    }
    vector_type size(void){
      return vector_size;
    }
    bool is_empty(void){
      for(int i=0; i<vector_size; i++){
        if(array[i]!=invalid){  return false;}
      }
      return true;
    }
    void push_back(vector_type input){
      for(int i=0; i<vector_size; i++){
        if(array[i]==invalid){
          array[i]=input; sort_invalid(); return;
        }
      }
    }
    void push_back_sort(vector_type input){
      for(int i=0; i<vector_size; i++){
        if(array[i]==invalid){
          array[i]=input; sort_invalid(); full_sort(); return;
        }
      }
    }
    void pop_back(void){
      for(int i=vector_size-1; i>=0; i--){
        if(array[i]!=invalid){  array[i]=invalid; return;}
        else{ continue;}
      }
    }
    void erase(int index){
      array[index]=invalid;
      sort_invalid();
    }
    void insert(int index, vector_type value){
      array[index]=value;
    }
    vector_type find(vector_type value){
      for(int i=0; i<vector_size; i++){
        if(array[i]!=invalid && array[i]==value){ return i;}
      }
    }
    bool is_full(void){
      for(int i=0; i<vector_size; i++){
        if(array[i]==invalid){  return false;}
      }
      return true;
    }
    void default_print(void){
      for(int i=0; i<vector_size; i++){
        if(array[i]!=invalid){  Serial.println(String((int)array[i]));}
        else{ break;}
      }
    }
};
template <int vector_size>
class Vector<vector_size, String>: public algorithm<String>{
  public: 
    const String invalid="invalid";
    String array[vector_size];
    Vector(){
      for(int i=0; i<vector_size; i++){
        array[i]=invalid;
      }
    }
    void sort_invalid(void){
      for(int i=0; i<vector_size; i++){
        for(int j=i+1; j<vector_size; j++){
          if(array[i]!=invalid && array[j]==invalid){
            continue;
          }
          else if(array[i]==invalid && array[j]!=invalid){
            array[i]=array[j];
            array[j]=invalid;
          }
          else if(array[i]==invalid && array[j]==invalid){
            continue;
          }
          else{
            continue;
          }
        }
      }
    }
    void full_sort(void){
      for(int i=0; i<vector_size; i++){
        for(int j=i+1; j<vector_size; j++){
          if(array[i]!=invalid && array[j]==invalid){
            continue;
          }
          else if(array[i]==invalid && array[j]!=invalid){
            array[i]=array[j];
            array[j]=invalid;
          }
          else if(array[i]==invalid && array[j]==invalid){
            continue;
          }
          else{
            continue;
          }
        }
      }
      for(int i=0; i<vector_size; i++){
        for(int j=i+1; j<vector_size; j++){
          if(array[i]!=array[j]){
            continue;
          }
          else{
            array[j]=invalid;
          }
        }
      }
      for(int i=0; i<vector_size; i++){
        for(int j=i+1; j<vector_size; j++){
          if(array[i]!=invalid && array[j]==invalid){
            continue;
          }
          else if(array[i]==invalid && array[j]!=invalid){
            array[i]=array[j];
            array[j]=invalid;
          }
          else if(array[i]==invalid && array[j]==invalid){
            continue;
          }
          else{
            continue;
          }
        }
      }
    }
    String front(void){
      return array[0];
    }
    String back(void){
      return array[vector_size-1];
    }
    String at(int index){
      if(array[index]!=invalid){  return array[index];}
      else{ return invalid;}
    }
    int size(void){
      return vector_size;
    }
    bool is_empty(void){
      for(int i=0; i<vector_size; i++){
        if(array[i]!=invalid){  return false;}
      }
      return true;
    }
    void push_back(String input){
      String string="";
      for(const char &ch: input){
        string+=char(tolower(ch));
      }
      for(int i=0; i<vector_size; i++){
        if(array[i]==invalid){
          array[i]=string; return;
        }
      }
    }
    void push_back_sort(String input){
      String string="";
      for(const char &ch: input){
        string+=char(tolower(ch));
      }
      for(int i=0; i<vector_size; i++){
        if(array[i]==invalid){
          array[i]=string; full_sort(); return;
        }
      }
    }
    void pop_back(void){
      for(int i=vector_size-1; i>=0; i--){
        if(array[i]!=invalid){  array[i]=invalid; return;}
        else{ continue;}
      }
    }
    void erase(int index){
      array[index]=invalid;
      sort_invalid();
    }
    void insert(int index, String value){
      String input="";
      for(const char &ch: value){
        input+=char(tolower(ch));
      }
      array[index]=input;
    }
    int find(String value){
      for(int i=0; i<vector_size; i++){
        if(array[i]!=invalid && array[i]==value){ return i;}
      }
    }
    bool is_full(void){
      for(int i=0; i<vector_size; i++){
        if(array[i]==invalid){  return false;}
      }
      return true;
    }
    void print(void){
      for(int i=0; i<vector_size; i++){
        if(array[i]!=invalid){  Serial.println(array[i]);}
        else{ break;}
      }
    }
};
template <int vector_size>
class Vector<vector_size, float>: public algorithm<float>{
  public: 
    const float invalid=0.0000;
    float array[vector_size];
    Vector(){
      for(int i=0; i<vector_size; i++){
        array[i]=invalid;
      }
    }
    void sort_invalid(void){
      for(int i=0; i<vector_size; i++){
        for(int j=i+1; j<vector_size; j++){
          if(array[i]!=invalid && array[j]==invalid){
            continue;
          }
          else if(array[i]==invalid && array[j]!=invalid){
            array[i]=array[j];
            array[j]=invalid;
          }
          else if(array[i]==invalid && array[j]==invalid){
            continue;
          }
          else{
            continue;
          }
        }
      }
    }
    void full_sort(void){
      for(int i=0; i<vector_size; i++){
        for(int j=i+1; j<vector_size; j++){
          if(array[i]!=invalid && array[j]==invalid){
            continue;
          }
          else if(array[i]==invalid && array[j]!=invalid){
            array[i]=array[j];
            array[j]=invalid;
          }
          else if(array[i]==invalid && array[j]==invalid){
            continue;
          }
          else{
            continue;
          }
        }
      }
      for(int i=0; i<vector_size; i++){
        for(int j=i+1; j<vector_size; j++){
          if(array[i]!=array[j]){
            continue;
          }
          else{
            array[j]=invalid;
          }
        }
      }
      for(int i=0; i<vector_size; i++){
        for(int j=i+1; j<vector_size; j++){
          if(array[i]!=invalid && array[j]==invalid){
            continue;
          }
          else if(array[i]==invalid && array[j]!=invalid){
            array[i]=array[j];
            array[j]=invalid;
          }
          else if(array[i]==invalid && array[j]==invalid){
            continue;
          }
          else{
            continue;
          }
        }
      }
    }
    float front(void){
      return array[0];
    }
    float back(void){
      return array[vector_size-1];
    }
    float at(int index){
      if(array[index]!=invalid){  return array[index];}
      else{ return invalid;}
    }
    int size(void){
      return vector_size;
    }
    bool is_empty(void){
      for(int i=0; i<vector_size; i++){
        if(array[i]!=invalid){  return false;}
      }
      return true;
    }
    void push_back(float input, int precision){
      for(int i=0; i<vector_size; i++){
        if(array[i]==invalid){
          array[i]=set_precision(precision, input); sort_invalid(); return;
        }
      }
    }
    void push_back_sort(float input, int precision){
      for(int i=0; i<vector_size; i++){
        if(array[i]==invalid){
          array[i]=set_precision(precision, input); full_sort(); return;
        }
      }
    }
    void pop_back(void){
      for(int i=vector_size-1; i>=0; i--){
        if(array[i]!=invalid){  array[i]=invalid; return;}
        else{ continue;}
      }
    }
    void erase(int index){
      array[index]=invalid;
      sort_invalid();
    }
    void insert(int index, float input, int precision){
      array[index]=set_precision(precision, input);
    }
    int find(float input, int precision){
      for(int i=0; i<vector_size; i++){
        if(array[i]!=invalid && array[i]==set_precision(precision, input)){ return i;}
      }
    }
    bool is_full(void){
      for(int i=0; i<vector_size; i++){
        if(array[i]==invalid){  return false;}
      }
      return true;
    }
    void print(int precision){
      for(int i=0; i<vector_size; i++){
        if(array[i]!=invalid){  Serial.println(array[i], precision);}
        else{ break;}
      }
    }
};
template <int vector_size>
class Vector<vector_size, char>: public algorithm<char>{
  public: 
    const char invalid='*';
    char array[vector_size];
    Vector(){
      for(int i=0; i<vector_size; i++){
        array[i]=invalid;
      }
    }
    void sort_invalid(void){
      for(int i=0; i<vector_size; i++){
        for(int j=i+1; j<vector_size; j++){
          if(array[i]!=invalid && array[j]==invalid){
            continue;
          }
          else if(array[i]==invalid && array[j]!=invalid){
            array[i]=array[j];
            array[j]=invalid;
          }
          else if(array[i]==invalid && array[j]==invalid){
            continue;
          }
          else{
            continue;
          }
        }
      }
    }
    void full_sort(void){
      for(int i=0; i<vector_size; i++){
        for(int j=i+1; j<vector_size; j++){
          if(array[i]!=invalid && array[j]==invalid){
            continue;
          }
          else if(array[i]==invalid && array[j]!=invalid){
            array[i]=array[j];
            array[j]=invalid;
          }
          else if(array[i]==invalid && array[j]==invalid){
            continue;
          }
          else{
            continue;
          }
        }
      }
      for(int i=0; i<vector_size; i++){
        for(int j=i+1; j<vector_size; j++){
          if(array[i]!=array[j]){
            continue;
          }
          else{
            array[j]=invalid;
          }
        }
      }
      for(int i=0; i<vector_size; i++){
        for(int j=i+1; j<vector_size; j++){
          if(array[i]!=invalid && array[j]==invalid){
            continue;
          }
          else if(array[i]==invalid && array[j]!=invalid){
            array[i]=array[j];
            array[j]=invalid;
          }
          else if(array[i]==invalid && array[j]==invalid){
            continue;
          }
          else{
            continue;
          }
        }
      }
    }
    char front(void){
      return array[0];
    }
    char back(void){
      return array[vector_size-1];
    }
    char at(int index){
      if(array[index]!=invalid){  return array[index];}
      else{ return invalid;}
    }
    int size(void){
      return vector_size;
    }
    bool is_empty(void){
      for(int i=0; i<vector_size; i++){
        if(array[i]!=invalid){  return false;}
      }
      return true;
    }
    void push_back(char input){
      for(int i=0; i<vector_size; i++){
        if(array[i]==invalid){
          array[i]=input; sort_invalid(); return;
        }
      }
    }
    void push_back_sort(char input){
      for(int i=0; i<vector_size; i++){
        if(array[i]==invalid){
          array[i]=input; full_sort(); return;
        }
      }
    }
    void pop_back(void){
      for(int i=vector_size-1; i>=0; i--){
        if(array[i]!=invalid){  array[i]=invalid; return;}
        else{ continue;}
      }
    }
    void erase(int index){
      array[index]=invalid;
      sort_invalid();
    }
    void insert(int index, char input){
      array[index]=input;
    }
    int find(char input){
      for(int i=0; i<vector_size; i++){
        if(array[i]!=invalid && array[i]==input){ return i;}
      }
    }
    bool is_full(void){
      for(int i=0; i<vector_size; i++){
        if(array[i]==invalid){  return false;}
      }
      return true;
    }
    void print(){
      for(int i=0; i<vector_size; i++){
        if(array[i]!=invalid){  Serial.println(char(array[i]));}
        else{ break;}
      }
    }
};
#endif