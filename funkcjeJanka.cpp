#include "hederJanka.h"


int glowna(int argc, char * argv[])
{
	CIniWriter iniWriter("D:\\Paths.ini");
	iniWriter.WriteString("Image", "Path1", "D:\\\Obrazy\\\gory.jpg");
	iniWriter.WriteString("Image", "Path2", "D:\\\Obrazy\\\jesien.jpg");
	iniWriter.WriteString("Image", "Path3", "D:\\\Obrazy\\\ksiezyc.jpg");
	iniWriter.WriteString("Image", "Path4", "D:\\\Obrazy\\\most.jpg");
	iniWriter.WriteString("Image", "Path5", "D:\\\Obrazy\\\zima.jpg");

	//iniWriter.WriteInteger("Image", "Path2", 27);
	//iniWriter.WriteFloat("Image", "Path3", 1.82f);
	//iniWriter.WriteBoolean("Image", "Path4", false);

	CIniReader iniReader("D:\\Paths.ini");
	char *Path1 = iniReader.ReadString("Image", "Path1", "");
	char *Path2 = iniReader.ReadString("Image", "Path2", "");
	char *Path3 = iniReader.ReadString("Image", "Path3", "");
	char *Path4 = iniReader.ReadString("Image", "Path4", "");
	char *Path5 = iniReader.ReadString("Image", "Path5", "");
	//int iAge = iniReader.ReadInteger("Setting", "Age", 25);
	//float fltHieght = iniReader.ReadFloat("Setting", "Height", 1.80f);
	//bool bMarriage = iniReader.ReadBoolean("Setting", "Marriage", true);

	std::cout << "Path1:" << Path1 << std::endl;
	std::cout << "Path2:" << Path2 << std::endl;
	std::cout << "Path3:" << Path3 << std::endl;
	std::cout << "Path4:" << Path4 << std::endl;
	std::cout << "Path5:" << Path5 << std::endl;
		//<< "Age:" << iAge << std::endl
		//<< "Height:" << fltHieght << std::endl
		//<< "Marriage:" << bMarriage << std::endl;
	
	std::vector <std::string> tablica;
	
	tablica.push_back(Path1);
	tablica.push_back(Path2);
	tablica.push_back(Path3);
	tablica.push_back(Path4);
	tablica.push_back(Path5);

	std::cout << "Vector:" << std::endl;
	std::cout << "Path1 = " << tablica[0] << std::endl;
	std::cout << "Path2 = " << tablica[1] << std::endl;
	std::cout << "Path3 = " << tablica[2] << std::endl;
	std::cout << "Path4 = " << tablica[3] << std::endl;
	std::cout << "Path5 = " << tablica[4] << std::endl;


	delete Path1;
	delete Path2;
	delete Path3;
	delete Path4;
	delete Path5;
	system("PAUSE");
	return 1;
}
//INI_READER
CIniReader::CIniReader(char* szFileName)
{
	memset(m_szFileName, 0x00, 255);
	memcpy(m_szFileName, szFileName, strlen(szFileName));
}
int CIniReader::ReadInteger(char* szSection, char* szKey, int iDefaultValue)
{
	int iResult = GetPrivateProfileInt(szSection, szKey, iDefaultValue, m_szFileName);
	return iResult;
}
float CIniReader::ReadFloat(char* szSection, char* szKey, float fltDefaultValue)
{
	char szResult[255];
	char szDefault[255];
	float fltResult;
	sprintf_s(szDefault, "%f", fltDefaultValue);
	GetPrivateProfileString(szSection, szKey, szDefault, szResult, 255, m_szFileName);
	fltResult = atof(szResult);
	return fltResult;
}
bool CIniReader::ReadBoolean(char* szSection, char* szKey, bool bolDefaultValue)
{
	char szResult[255];
	char szDefault[255];
	bool bolResult;
	sprintf_s(szDefault, "%s", bolDefaultValue ? "True" : "False");
	GetPrivateProfileString(szSection, szKey, szDefault, szResult, 255, m_szFileName);
	bolResult = (strcmp(szResult, "True") == 0 ||
		strcmp(szResult, "true") == 0) ? true : false;
	return bolResult;
}
char* CIniReader::ReadString(char* szSection, char* szKey, const char* szDefaultValue)
{
	char* szResult = new char[255];
	memset(szResult, 0x00, 255);
	GetPrivateProfileString(szSection, szKey,
		szDefaultValue, szResult, 255, m_szFileName);
	return szResult;
}
//INI_WRITER
CIniWriter::CIniWriter(char* szFileName)
{
	memset(m_szFileName, 0x00, 255);
	memcpy(m_szFileName, szFileName, strlen(szFileName));
}
void CIniWriter::WriteInteger(char* szSection, char* szKey, int iValue)
{
	char szValue[255];
	sprintf_s(szValue, "%d", iValue);
	WritePrivateProfileString(szSection, szKey, szValue, m_szFileName);
}
void CIniWriter::WriteFloat(char* szSection, char* szKey, float fltValue)
{
	char szValue[255];
	sprintf_s(szValue, "%f", fltValue);
	WritePrivateProfileString(szSection, szKey, szValue, m_szFileName);
}
void CIniWriter::WriteBoolean(char* szSection, char* szKey, bool bolValue)
{
	char szValue[255];
	sprintf_s(szValue, "%s", bolValue ? "True" : "False");
	WritePrivateProfileString(szSection, szKey, szValue, m_szFileName);
}
void CIniWriter::WriteString(char* szSection, char* szKey, char* szValue)
{
	WritePrivateProfileString(szSection, szKey, szValue, m_szFileName);
}