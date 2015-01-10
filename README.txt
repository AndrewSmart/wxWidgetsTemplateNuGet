# wxWidgetsTemplateNuGet
This is the source for a NuGet package which assists projects that depend on wxWidgets.
Technology described here: http://blogs.msdn.com/b/vcblog/archive/2013/06/18/deep-dive-into-nuget-native-part-one.aspx
Guide to installing this package ande configuring it is here: https://wiki.wxwidgets.org/Microsoft_Visual_C++_NuGet

The package will automatically create and use a precompiled header file exclusively for wxWidgets. Note the precompiled header deployed by this package wasn't designed to be modifiable as modifications would be removed if the NuGet package were updated. It is a shim to be honest- this shim more than halves compilation time as wxWidgets is large. I suggest you use your own PCH if you want to optimize compilation time on other code in your project as well.

Directions: Place the following at the top of all of your .cpp files which use wxWidgets.
```cpp
#include <wx/wxprec.h>
```
If the .cpp needs something not in wx/wx.h, then place it below the above in the cpp file. e.g.:
```cpp
#include <wx/wxprec.h> //This must be above other wx includes.
#include <wx/thread.h>
#include <wx/xml/xml.h>
#include <wx/string.h> //Not necessary as wx/string.h is already included in the wx/wx.h (in the PCH).
```

Details (see https://wiki.wxwidgets.org/Precompiled_Headers):
 * By default all C++ files have the following settings as per the project properties:
   * **`Precompiled Header: Use (/Yu)`**
   * **`Precompiled Header File: wx/wxprec.h`**
   * **`Precompiled Header File: $(ProjectDir)$(IntDir)$(TargetName).pch`**
 * The CreateProcompiledHeaderFileProcess.cpp file is set to  **`Precompiled Header: Create (/Yu)`**, as one .cpp file must be set as such in order for the .pch file to be generated.
 * Define NOPCH in the preprocessor project property in order to disable this functionality (see the SetCreatePrecompiledHeaderFile target in [./build/wxWidgetsTemplate.targets](https://github.com/AndrewSmart/wxWidgetsTemplateNuGet/blob/master/build/wxWidgetsTemplate.targets) for implementation details).
   * This might not work as reported by email I received. Due to the considerable increase in compilation time I suggest you create your own PCH instead of attempting to disable this.
 * If using your own PCH such as stdafx.h you'll need to define that manually: *Project properties -> Configuration properties -> C/C++ -> Precompiled Headers -> Precompiled Header File: stdafx.h*
 
 Author's notes:
  * I currently do not maintain any wxWidgets projects, or have any edition of Visual Studio. If you identify bugs, please submit a pull request on GitHub.
  * Having CreateProcompiledHeaderFileProcess.h contain the includes, and CreateProcompiledHeaderFileProcess.cpp including that .h file would be the ideal design. I don't think there are any pitfalls from the current arrangement, though would welcome that fix.
