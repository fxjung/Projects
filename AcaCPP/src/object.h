#pragma once

class Object
{
public:
  Object(char* name);
  ~Object();

  /// Returns ID which was passed in the constructor.
  char* GetName() { return m_name; };

private:

  char* m_name;

  // Here could be YOUR data!
};

