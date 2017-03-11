#ifndef FLOWCROWDS_SHADERHANDLER_HDR
#define FLOWCROWDS_SHADERHANDLER_HDR

#include <string>
#include <map>

namespace Shader {
	struct IProgramObject;
	struct IShaderObject;
};

class CShaderHandler {
public:
	static CShaderHandler* GetInstance();

	void ReleaseProgramObjects(const std::string&);
	Shader::IProgramObject* CreateProgramObject(const std::string&, const std::string&, bool);
	Shader::IProgramObject* CreateProgramObject(
		const std::string&,
		const std::string&,
		const std::string&,
		const std::string&,
		const std::string&,
		const std::string&,
		bool
	);
	Shader::IShaderObject* CreateShaderObject(const std::string&, const std::string&, int);

private:
	typedef std::map<std::string, Shader::IProgramObject*> ProgramObjMap;
	typedef std::map<std::string, Shader::IProgramObject*>::iterator ProgramObjMapIt;

	std::map<std::string, ProgramObjMap> programObjects;
};

#define shaderHandler (CShaderHandler::GetInstance())

#endif