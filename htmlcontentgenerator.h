#ifndef HTMLCONTENTGENERATOR_H
#define HTMLCONTENTGENERATOR_H

#include "generator.h"
#include "configurable.h"

class HTMLContentGenerator : public Generator, public Configurable
{
public:
  std::string generate(const std::string &path);

  // Configurable interface
public:
  virtual void setConfiguration(Configuration configuration) override;
};

#endif // HTMLCONTENTGENERATOR_H
