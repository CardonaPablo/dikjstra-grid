{
  "targets": [
    {
      "target_name": "addon",
      "sources": [ "engine/main.cc" ],
      'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ],
      "include_dirs": [
        "<!(node -p \"require('node-addon-api').include_dir\")"
      ],
    }
  ],
}