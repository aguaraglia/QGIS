/*
 MDAL - Mesh Data Abstraction Library (MIT License)
 Copyright (C) 2018 Peter Petrik (zilolv at gmail dot com)
*/

#include "mdal_utils.hpp"
#include <fstream>

bool MDAL::fileExists( const std::string &filename )
{
  std::ifstream in( filename );
  return in.good();
}


bool MDAL::startsWith( const std::string &str, const std::string &substr )
{
  return str.rfind( substr, 0 ) == 0;
}

std::vector<std::string> MDAL::split( const std::string &str, const std::string &delimiter, SplitBehaviour behaviour )
{
  std::string remaining( str );
  std::vector<std::string> list;
  size_t pos = 0;
  std::string token;
  while ( ( pos = remaining.find( delimiter ) ) != std::string::npos )
  {
    token = remaining.substr( 0, pos );

    if ( behaviour == SplitBehaviour::SkipEmptyParts )
    {
      if ( !token.empty() )
        list.push_back( token );
    }
    else
      list.push_back( token );

    remaining.erase( 0, pos + delimiter.length() );
  }
  list.push_back( remaining );
  return list;
}

size_t MDAL::toSizeT( const std::string &str )
{
  int i = atoi( str.c_str() );
  if ( i < 0 ) // consistent with atoi return
    i = 0;
  return i;
}

double MDAL::toDouble( const std::string &str )
{
  return atof( str.c_str() );
}
