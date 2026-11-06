// swift-tools-version:5.9
// Swift Package Manager distribution of the Jibestream ZoneKit, starting at 3.0.0.
// The same git tag also serves the CocoaPods podspec (ZoneKit-iOS-Pod.podspec) until
// CocoaPods is retired.
//
// Release: tag the commit with the bare semantic version (e.g. `3.0.0`, no `v` prefix) and keep
// `s.version` in ZoneKit-iOS-Pod.podspec in step with it.
import PackageDescription

let package = Package(
    name: "ZoneKit-iOS-Pod",
    platforms: [
        // Must be at least the JMapiOSSDK package's own floor, or SPM refuses to resolve the
        // graph. The shipped binary is built for iOS 10 and stays forward-compatible, so this
        // is a policy floor rather than a technical one.
        .iOS(.v15)
    ],
    products: [
        // ZoneKitSPMSupport ships in the same product as the binary target on purpose: see its
        // comment below. A consumer adds this one product and gets both.
        .library(
            name: "JMapZoneKit",
            targets: ["JMapZoneKit", "ZoneKitSPMSupport"]
        )
    ],
    dependencies: [
        // RC pin, not the final form. JMapiOSSDK 6.0.0 is not tagged yet, and an SPM range
        // requirement such as `from:` never matches a prerelease. Flip this to
        // `from: "6.0.0"` once JMap-iOS-SDK-Pod tags 6.0.0, before this branch merges.
        .package(url: "https://github.com/Jibestream/JMap-iOS-SDK-Pod.git", exact: "6.0.0-rc1")
    ],
    targets: [
        // Static Objective-C framework containing no Objective-C categories of its own, so it
        // adds no -ObjC requirement beyond the one JMapiOSSDK already imposes.
        //
        // The archive carries no LC_LINKER_OPTION, so it auto-links nothing by itself. Its
        // system frameworks are linked through the consumer's Clang module graph instead: its
        // public headers import Foundation and UIKit, and JMapRenderingKit's import WebKit.
        // Verified by linking and running an app against all six modules with -ObjC, where
        // CoreLocation and WebKit both end up in the app binary. Hence no linkerSettings here.
        .binaryTarget(
            name: "JMapZoneKit",
            path: "ZoneKit-iOS-Pod/Frameworks/JMapZoneKit.xcframework"
        ),
        // Exists only to carry the JMapiOSSDK dependency edge, which `.binaryTarget` cannot
        // declare. JMapZoneKit's public headers `#import <JMapCoreKit/...>`,
        // `<JMapRenderingKit/...>` and `<JMapControllerKit/...>`, so without this edge
        // `import JMapZoneKit` fails to compile with "'JMapCoreKit/JMapCoreKit.h' file not found".
        .target(
            name: "ZoneKitSPMSupport",
            dependencies: [.product(name: "JMapiOSSDK", package: "JMap-iOS-SDK-Pod")]
        )
    ]
)
