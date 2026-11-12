// Intentionally empty.
//
// This target carries ZoneKit-iOS-Pod's dependency on JMapiOSSDK. SPM's `.binaryTarget`
// accepts no `dependencies:`, and JMapZoneKit's public headers `#import` the JMapiOSSDK
// umbrella headers, so the edge has to live on a regular target that ships in the same
// product. SwiftPM rejects a target with no sources, hence this file.
//
// Do not add API here. JMapZoneKit is what consumers import.
