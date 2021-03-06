#ifndef HTMLCONTENTGENERATOR_H
#define HTMLCONTENTGENERATOR_H

#include "configurable.h"
#include "generator.h"

class HTMLContentGenerator : public Generator, public Configurable
{
public:
  ~HTMLContentGenerator() override;
  std::string generate(const std::string &path) override;

  // Configurable interface
public:
  virtual void setConfiguration(Configuration configuration) override;

};

#endif // HTMLCONTENTGENERATOR_H
