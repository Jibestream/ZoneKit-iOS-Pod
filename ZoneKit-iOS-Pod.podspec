Pod::Spec.new do |s|
  s.name             = 'ZoneKit-iOS-Pod'
  s.version          = '0.1.0'
  s.summary          = 'The ZoneKit-iOS-Pod for the Jibestream iOS SDK.'

  s.description      = 'This CocoaPod provides the release version of the ZoneKit for the Jibestream iOS SDK.'

  s.homepage         = 'https://github.com/louieyune/ZoneKit-iOS-Pod'
  s.author           = { 'louie' => 'lyuen@jibestream.com' }
  s.source           = { :git => 'https://github.com/louieyune/ZoneKit-iOS-Pod.git', :tag => "#{s.version}" }

  s.ios.deployment_target = '9.0'

  s.source_files = 'ZoneKit-iOS-Pod/Classes/**/*'
  s.platform = :ios, '9.0'
  s.vendored_frameworks = 'ZoneKit-iOS-Pod/Frameworks/*.framework'
  
end
