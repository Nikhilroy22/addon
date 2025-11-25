{
  "targets": [
    {
      "target_name": "addon",
      "sources": ["addon.cpp"],
      "include_dirs": [
        "<!(echo ./node-headers)"
      ]
    }
  ]
}