<?php

function text_extraction_form_settings() {
   $form['extract_content_type'] = array(
      '#type'          => 'checkboxes',
      '#title'         => t("Content Type"),
      '#default_value' => variable_get('extract_content_type', FALSE),
      '#options'       => text_extract_get_content_types(),
    );
   $form['extract_content_number'] = array(
      '#type'    => 'textfield',
      '#default_value' => variable_get('extract_content_number', FALSE),
      '#title'   => t("Number of docs per cron run"),
      '#size'    => 3,
    );
   $form['extract_during_cron'] = array(
      '#type' => 'checkbox', 
      '#default_value' => variable_get('extract_during_cron', FALSE),
      '#title' => t('Extract the selected content types during Cron Run'),
    );
   return system_settings_form($form);
}

function text_extract_get_content_types() {
  $query = db_query("SELECT name, type FROM {node_type}");
  while($data = db_fetch_array($query)) {
    $content_types[$data['type']] = $data['name'];
  }
  return $content_types;
}