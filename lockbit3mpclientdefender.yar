// Rule for https://www.bleepingcomputer.com/news/security/lockbit-ransomware-abuses-windows-defender-to-load-cobalt-strike/

import "pe"
import "hash"

rule LockBit3MpClientDefender {
	strings:
		// name of the dll visible in the strings
		$keyword1 = "mpclient.dll"
		// exported methods used by mpclient.dll for the dll hijacking (all are necessary or the dll hijacking will not work)
		$keyword2 = "MpConfigClose"
		$keyword3 = "MpConfigGetValueAlloc"
		$keyword4 = "MpHandleClose"
		$keyword5 = "MpManagerOpen"
		$keyword6 = "MpFreeMemory"
		$keyword7 = "MpConfigUninitialize"
		$keyword8 = "MpConfigOpen"
		$keyword9 = "MpConfigInitialize"
		$keyword10 = "MpClientUtilExportFunctions"
		$keyword11 = "MpUtilsExportFunctions"
	condition:
		// checking if the dll is signed by microsoft
		for any i in (0 .. pe.number_of_signatures) : (
			pe.signatures[i].issuer contains "Microsoft Windows Production PCA 2011" and
			pe.signatures[i].serial == "33:00:00:02:31:32:34:cb:af:a8:ab:9a:4d:00:00:00:00:02:31"
		) and
		// checking if all keywords are present
		all of ($keyword*)
}
